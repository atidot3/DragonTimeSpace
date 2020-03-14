#include "Logger.h"
#include <Configuration\Configuration.h>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace keywords = boost::log::keywords;

BOOST_LOG_GLOBAL_LOGGER_INIT(my_logger, boost::log::sources::severity_logger_mt)
{
	boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> logger;

	logging::add_file_log(
		keywords::file_name = sConfig.GetLogFile(),
		keywords::auto_flush = true,
		keywords::open_mode = (std::ios::out | std::ios::app),
		keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
		keywords::format = (
			expr::stream
			<< expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "[%Y-%m-%d]:[%H:%M:%S]:<")
			<< boost::log::trivial::severity << "> "
			<< expr::smessage
			)
	);
	logging::add_console_log(std::cout, keywords::format = (
		expr::stream
		<< expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "[%Y-%m-%d]:[%H:%M:%S]:<")
		<< boost::log::trivial::severity << "> "
		<< expr::smessage
		));

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= sConfig.GetLogLevel()
	);

	logging::add_common_attributes();

	return logger;
}