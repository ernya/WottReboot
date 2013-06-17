#include "SimpleFragmentShader.hpp"
#include "ShaderTools.hpp"

SimpleFragmentShader::SimpleFragmentShader() : AShader(ShaderTools::loadShaderFile("fs.txt"), AShader::VERTEX_SHADER)
{
}

