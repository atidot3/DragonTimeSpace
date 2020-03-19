#include <boost/exception/all.hpp>
#include <boost/filesystem.hpp>

#include <iostream>
#include <cstdio>
#include <sstream>
#include <random>
#include <string>
#include <set>
#include <thread>
#include <mutex>

#include <Utils/Logger/Logger.h>
#include <Configuration/Configuration.h>
#include <Network/io_context_pool.h>
#include <Database/MySQLWrapper.h>

#define twop22 (0x1.0p+22)
#define ABS(x) (fabs(x))
#define isFloatInteger(x) ((ABS(x) >= twop22) || (((ABS(x) + twop22) - twop22) == ABS(x)))

unsigned int random_char()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(48, 90);
	return dis(gen);
}

std::mutex _key_secure_mutex;
std::vector<std::string> keys;
int amount;
int thread_amount;

void GenerateKey(const unsigned int& amount)
{
	for (auto i = 0; i < amount; ++i)
	{
		std::string KEY = std::string(24, ' ');
		int rnd = 0;
		int r = 0;

		KEY[4] = '-';
		KEY[9] = '-';
		KEY[14] = '-';
		KEY[19] = '-';

		for (int i = 0; i < 24; i++)
		{
			if (i != 4 && i != 9 && i != 14 && i != 19)
			{
				unsigned char c = (unsigned char)random_char();
				while (c >= 58 && c <= 64)
					c = (unsigned char)random_char();
				KEY[i] = c;
			}
		}
		_key_secure_mutex.lock();
		keys.emplace_back(KEY);
		float total = amount * thread_amount;
		float val = keys.size() / total;
		float percent = val * 100;
		int check = percent;
		if (check == percent)
		{
			system("CLS");
			std::cout << percent << " %" << std::endl << std::flush;
		}
		_key_secure_mutex.unlock();
	}
}


int main()
{
	try
	{
		sConfig.Load("./KeyGenerator.json");

		LOG_TRACE << "=========== Logger initialized ===========";
		LOG_INFO << "\t     ____                              ____        _ _ ";
		LOG_INFO << "\t    |  _ \\ _ __ __ _  __ _  ___  _ __ | __ )  __ _| | |";
		LOG_INFO << "\t    | | | | '__/ _` |/ _` |/ _ \\| '_ \\|  _ \\ / _` | | |";
		LOG_INFO << "\t    | |_| | | | (_| | (_| | (_) | | | | |_) | (_| | | |";
		LOG_INFO << "\t    |____/|_|  \\__,_|\\__, |\\___/|_| |_|____/ \\__,_|_|_|";
		LOG_INFO << "\t                     |___/                             ";
		LOG_INFO << "\t   	           AKCore 2019					\n";

		std::cout << "Key amount to generate: ";
		std::cin >> amount;
		std::cout << "Amount of thread to work on: ";
		std::cin >> thread_amount;
		std::cout << "Generating: " << amount << " keys" << std::endl;


		if (amount == 0 || thread_amount <= 0)
		{
			return -1;
		}
		// -- 0-9 -> 48 - 57
		// -- A-Z -> 65 - 90

		std::vector<std::thread> _threads;
		for (int i = 0; i < thread_amount; ++i)
		{
			std::thread t = std::thread([]()
			{
				GenerateKey(amount / thread_amount);
			});
			_threads.emplace_back(std::move(t));
		}
		for (auto &c : _threads)
		{
			c.join();
		}

		std::cout << amount << " key generated, checking for duplicated entry..." << std::endl;

		sort(keys.begin(), keys.end());
		std::set<std::string> uvec(keys.begin(), keys.end());
		std::list<std::string> output;
		std::set_difference(keys.begin(), keys.end(),
			uvec.begin(), uvec.end(),
			back_inserter(output));

		if (output.size() > 0)
		{
			LOG_DEBUG << "Duplicated key: ";
			for (auto& c : output)
			{
				std::cout << c << std::endl;
			}
		}
		else
		{
			// -- we can add theese key into our database
			LOG_INFO << "No duplicated key, type Y to insert it in database";
			char c;
			std::cin >> c;
		}
	}
	catch (std::exception& e)
	{
		LOG_FATAL << "Exception catch: " << std::string(e.what());
	}
	catch (boost::exception const& e)
	{
		LOG_FATAL << "Error on main: [" << boost::diagnostic_information(e) << "]";
	}
	LOG_TRACE << "=========== Application exited. ===========";

	return EXIT_SUCCESS;
}
