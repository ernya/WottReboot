#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include "Global.hpp"

class Logging
{
public:
	enum error_level
	{
		E_DEBUG,
		E_INFO,
		E_WARNING,
		E_ERROR,
		E_SEVERE,
		E_FATAL
	};

	static void end()
	{
		delete _file;
	}

	static void log(error_level lvl, const std::string &message)
	{
		if (lvl > E_ERROR)
			std::cout <<  _errorHeaders.at(lvl) << message << std::endl;
		if (_file->fail())
		{
			return ;
		}
		(*_file) << _errorHeaders.at(lvl) << message << std::endl;
	}

	static void debug(const std::string &message)
	{
		log(E_DEBUG, message);
	}

	static void info(const std::string &message)
	{
		log(E_INFO, message);
	}
	
	static void warning(const std::string &message)
	{
		log(E_WARNING, message);
	}
	
	static void error(const std::string &message)
	{
		log(E_ERROR, message);
	}
	
	static void severe(const std::string &message)
	{
		log(E_SEVERE, message);
	}
	
	static void fatal(const std::string &message)
	{
		log(E_FATAL, message);
	}
private:
	static std::ostream *_file;
	static const std::map<error_level, std::string> createErrorHeaders()
	{
		std::map<error_level, std::string> errorHeaders;
		errorHeaders[E_DEBUG] = std::string("[DEBUG]  : ");
		errorHeaders[E_INFO] = std::string("[INFO]   : ");
		errorHeaders[E_WARNING] = std::string("[WARNING]: ");
		errorHeaders[E_ERROR] = std::string("[ERROR]  : ");
		errorHeaders[E_SEVERE] = std::string("[SEVERE] : ");
		errorHeaders[E_FATAL] = std::string("[FATAL]  : ");
		return errorHeaders;
	}
	static const std::map<error_level, std::string> _errorHeaders;
};
