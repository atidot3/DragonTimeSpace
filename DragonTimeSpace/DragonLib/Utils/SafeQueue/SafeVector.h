#ifndef _SAFEVECTOR_H_
#define _SAFEVECTOR_H_

#pragma once

#include <queue>
#include <list>
#include <mutex>
#include <thread>
#include <cstdint>
#include <condition_variable>



/** A thread-safe asynchronous queue */
template <class T, class Container = std::vector<T>>
class SafeVector
{
	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;
	typedef Container container_type;
public:

	/*! Create safe queue. */
	SafeVector()
		: m_queue{}
		, m_condition{}
		, m_max_num_items{ 0 }
	{
		m_queue.reserve(50);
	}
	SafeVector(SafeVector&& sq)
	{
		m_queue = std::move(sq.m_queue);
	}
	SafeVector(const SafeVector& sq)
	{
		std::lock_guard<std::mutex> lock(sq.m_mutex);
		m_queue = sq.m_queue;
	}

	/*! Destroy safe queue. */
	~SafeVector()
	{
		std::lock_guard<std::mutex> lock(m_mutex);
	}

	/**
	* Sets the maximum number of items in the queue. Defaults is 0: No limit
	* \param[in] item An item.
	*/
	void set_max_num_items(unsigned int max_num_items)
	{
		m_max_num_items = max_num_items;
	}

	/**
	*  Pushes the item into the queue.
	* \param[in] item An item.
	* \return true if an item was pushed into the queue
	*/
	bool push(const value_type& item)
	{
		std::lock_guard<std::mutex> lock(m_mutex);

		if (m_max_num_items > 0 && m_queue.size() > m_max_num_items)
			return false;

		m_queue.push_back(item);
		m_condition.notify_one();
		return true;
	}
	/**
	*  Pushes the item into the queue.
	* \param[in] item An item.
	* \return true if an item was pushed into the queue
	*/
	bool push(const value_type&& item)
	{
		std::lock_guard<std::mutex> lock(m_mutex);

		if (m_max_num_items > 0 && m_queue.size() > m_max_num_items)
			return false;

		m_queue.push_back(item);
		m_condition.notify_one();
		return true;
	}

	/**
	*  Pops item from the queue. If queue is empty, this function blocks until item becomes available.
	* \param[out] item The item.
	*/
	void pop(value_type& item)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		m_condition.wait(lock, [this]() // Lambda funct
			{
				return !m_queue.empty();
			});
		item = (*m_queue.begin());
		m_queue.erase(m_queue.begin());
	}

	void pop()
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		m_condition.wait(lock, [this]() // Lambda funct
			{
				return !m_queue.empty();
			});
		m_queue.erase(m_queue.begin());
	}

	value_type& get_front_reference(bool& sucess)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		if (!m_queue.empty())
		{
			sucess = true;
			m_condition.notify_one();
			return m_queue.front();
		}
		sucess = false;
		m_condition.notify_one();
		return value_type();
	}

	/**
	*  Gets the number of items in the queue.
	* \return Number of items in the queue.
	*/
	size_type size() const
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		return m_queue.size();
	}

	/**
	*  Check if the queue is empty.
	* \return true if queue is empty.
	*/
	bool empty() const
	{
		std::lock_guard<std::mutex> lock(m_mutex);
		return m_queue.empty();
	}


	/*! The copy assignment operator not available */
	SafeVector& operator= (const SafeVector& sq) = delete;
	/*! The move assignment operator is not available */
	SafeVector& operator= (SafeVector&& sq) = delete;

private:

	std::vector<T> m_queue;
	mutable std::mutex m_mutex;
	std::condition_variable m_condition;
	unsigned int m_max_num_items = 0;
};

#endif // !_SAFEVECTOR_H_