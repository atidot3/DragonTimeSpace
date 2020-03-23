#pragma once

#include <Utils/Define.h>

#include "../Object.h"

class Health
{
public:
	Health();
	const uint32_t& get_max_health() const;
	const uint32_t& get_cur_health() const;

	void set_max_health(const uint32_t& max);
	void set_cur_health(const uint32_t& cur);
private:
	uint32_t _max_hp, _cur_hp;
};

class Entity : public Object
{
public:
	Entity();
	// -- CONST GETTER
	const Object& get_object() const;
	const Health& get_health() const;
	const std::string get_name() const;

	// GETTER EDITABLE
	Object& get_object();
	Health& get_health();
	std::string& get_name();

	// -- SETTER
	void set_name(const std::string& name);
	void update_health(const uint32_t& cur_health);
	void update_max_health(const uint32_t& max_health);

private:
	Health			_health;
	std::string		_name;
};
