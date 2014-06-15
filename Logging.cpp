#include "Logging.hpp"


std::ostream *Logging::_file = new std::fstream(ROOTLOGPATH + "engine.log", std::fstream::out);
const std::map<Logging::error_level, std::string> Logging::_errorHeaders =  Logging::createErrorHeaders();