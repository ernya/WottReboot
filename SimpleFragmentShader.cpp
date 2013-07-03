#include "SimpleFragmentShader.hpp"
#include "ShaderTools.hpp"
#include "Global.hpp"

SimpleFragmentShader::SimpleFragmentShader() : AShader(ShaderTools::loadShaderFile("fs.txt"), AShader::FRAGMENT_SHADER)
{
}

