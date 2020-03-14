#ifndef _UTILS_H_
#define _UTILS_H_

#pragma once

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string_view>

#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <boost/algorithm/string.hpp>

inline bool IsLetters(const std::string_view& input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		int uppercaseChar = toupper(input[i]); //Convert character to upper case version of character
		if (uppercaseChar < 'A' || uppercaseChar > 'Z') //If character is not A-Z
		{
			return false;
		}
	}
	//At this point, we have gone through every character and checked it.
	return true; //Return true since every character had to be A-Z
}
inline bool IsAlpha(const std::string_view& input)
{
	std::string::size_type i = 0;
	while ((i < input.length()) && (std::isalpha(input[i])))
	{
		++i;
	}
	if (i == input.size())
		return true;
	return false;
}
inline bool IsAlphaNum(const std::string_view& input)
{
	std::string::size_type i = 0;
	while ((i < input.length()) && (std::isalnum(input[i])))
	{
		++i;
	}
	if (i == input.size())
		return true;
	return false;
}
inline bool EscapeString(const std::string_view& input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (
			input[i] == '\x07'
			|| input[i] == '\x08'
			|| input[i] == '\x09'
			|| input[i] == '\x0A'
			|| input[i] == '\x0B'
			|| input[i] == '\x0C'
			|| input[i] == '\x0D'
			|| input[i] == '\x1B'

			|| input[i] == '\\'
			|| input[i] == '\"'
			|| input[i] == '\''
			|| input[i] == '\?'
			|| input[i] == '\0'
			|| input[i] == '`'
			|| input[i] == '%%'
			)
			return false;
	}
	return true;
}
inline void ToLower(const std::string& input)
{
	std::string::size_type i = 0;
	while (i < input.length())
	{
		std::tolower(input[i]);
		++i;
	}
}

inline static wchar_t* charToWChar(const char* text)
{
	size_t conv, size = strlen(text) + 1;
	wchar_t* wa = new wchar_t[size];
	mbstowcs_s(&conv, wa, size, text, size);
	return wa;
}

inline std::string GenerateToken()
{
	const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	int stringLength = sizeof(alphanum) - 1;

	std::string token;

	for (int i = 0; i < 16; i++)
	{
		token += alphanum[rand() % stringLength];
	}
	return token;
}

// probability is from 1 to 100
inline bool successRand(const float& probability)
{
	return rand() % 100 + 1 < (probability);
}

// get a range around a point
inline float getRandomRange(const float& point, const int& rangesize)
{
	float newPoint = point;
	if (rand() % 50 + 1 < 50)
	{
		newPoint += rand() % rangesize + 1 + (rangesize * -1);
	}
	else
	{
		newPoint -= rand() % rangesize + 1 + (rangesize * -1);
	}
	return newPoint;
}

inline std::string decode64(const std::string &val)
{
	using namespace boost::archive::iterators;
	using It = transform_width<binary_from_base64<std::string::const_iterator>, 8, 6>;
	return boost::algorithm::trim_right_copy_if(std::string(It(std::begin(val)), It(std::end(val))), [](char c) {
		return c == '\0';
	});
}

inline std::string encode64(const std::string &val)
{
	using namespace boost::archive::iterators;
	using It = base64_from_binary<transform_width<std::string::const_iterator, 6, 8>>;
	auto tmp = std::string(It(std::begin(val)), It(std::end(val)));
	return tmp.append((3 - val.size() % 3) % 3, '=');
}

#define DBO_BIT_FLAG(x)			(1 << (x))
#define BIT_FLAG_TEST(x,y)		(((x) & (y))!=0)
#define BITFIELD_FLAG_TEST(bitField, bitNum) BIT_FLAG_TEST(bitField[bitNum / 8], 1 << ((bitNum) %8)) 
#endif /* _UTILS_H_ */