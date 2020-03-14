#include "Time.h"

time_t to_time_t(const boost::gregorian::date& date)
{
	using namespace boost::posix_time;
	static ptime epoch(boost::gregorian::date(1970, 1, 1));
	time_duration::sec_type secs = (ptime(date, seconds(0)) - epoch).total_seconds();
	return time_t(secs);
}
std::string GetDateInAMonth()
{
	const boost::gregorian::date now(boost::gregorian::day_clock::local_day_ymd());
	boost::gregorian::months monthObj(1);
	boost::gregorian::date validity = now + monthObj;
	std::string date = std::to_string(validity.year()) + "-" + std::to_string(validity.month()) + "-" + std::to_string(validity.day());

	return date;
}
std::string GetDateInDays(const int& daysAmount)
{
	const boost::gregorian::date now(boost::gregorian::day_clock::local_day_ymd());
	boost::gregorian::days monthObj(daysAmount);
	boost::gregorian::date validity = now + monthObj;
	std::string date = std::to_string(validity.year()) + "-" + std::to_string(validity.month()) + "-" + std::to_string(validity.day());

	return date;
}
std::string now()
{
	const boost::gregorian::date now(boost::gregorian::day_clock::local_day_ymd());
	std::string date = std::to_string(now.year()) + "-" + std::to_string(now.month()) + "-" + std::to_string(now.day());

	return date;
}
