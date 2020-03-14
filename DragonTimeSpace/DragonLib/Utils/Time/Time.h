#ifndef _TIME_H_
#define _TIME_H_

#pragma once

#include <string>
#include <ctime>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

// get a timestamp from a given date
time_t to_time_t(const boost::gregorian::date& date);
// get a time as string (Y-MM-DD) in 1 month
std::string GetDateInAMonth();
// get a time as string (Y-MM-DD) in x day
std::string GetDateInDays(const int& daysAmount);
// get now as string (Y-MM-DD)
std::string now();

#endif // !_TIME_H_