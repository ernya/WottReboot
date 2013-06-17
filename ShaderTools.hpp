#pragma once

#include <sstream>
#include <fstream>
#include <iostream>

class ShaderTools
{
public:
	static const std::string loadShaderFile(const std::string &filename)
	{
		std::ifstream fichier (filename.c_str());

		if (fichier)
		{
			std::stringstream buffer;
			buffer << fichier.rdbuf();
			fichier.close();
			std::string source (buffer.str());
			source.push_back ('\0');
			return source;
		}
		return std::string("");
	}
};