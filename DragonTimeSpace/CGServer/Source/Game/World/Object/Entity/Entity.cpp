#include "Entity.h"

// --------------------- HEALTH

Health::Health()
	: _max_hp{ 0 }
	, _cur_hp{ 0 }
{

}

const uint32_t& Health::get_max_health() const
{
	return _max_hp;
}

const uint32_t& Health::get_cur_health() const
{
	return _cur_hp;
}

void Health::set_max_health(const uint32_t& max)
{
	_max_hp = max;
}

void Health::set_cur_health(const uint32_t& cur)
{
	_cur_hp = cur;
}

// --------------------- ENTITY

Entity::Entity()
	: _health{ }
	, _name{}
{

}

const Object& Entity::get_object() const
{
	return (Object)*this;
}

const Health& Entity::get_health() const
{
	return _health;
}

const std::string Entity::get_name() const
{
	return _name;
}

Object& Entity::get_object()
{
	return (Object)*this;
}

Health& Entity::get_health()
{
	return _health;
}

std::string& Entity::get_name()
{
	return _name;
}

void Entity::set_name(const std::string& name)
{
	_name = name;
}

void Entity::update_health(const uint32_t& cur_health)
{
	_health.set_cur_health(cur_health);
}

void Entity::update_max_health(const uint32_t& max_health)
{
	_health.set_max_health(max_health);
}

uint64_t Entity::GenernateBuffHash(const uint64_t& entryID, const uint64_t& userState, const uint64_t& entrytype, const uint64_t& uniqueID)
{
	return (userState & 65535UL) << 48 | (uniqueID & 255UL) << 40 | (entrytype & 255UL) << 32 | (entryID & (uint64_t)-1);
}