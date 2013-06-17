#include "SimpleVertexShader.hpp"
#include "ShaderTools.hpp"

SimpleVertexShader::SimpleVertexShader() : AShader(ShaderTools::loadShaderFile("vs.txt"), AShader::VERTEX_SHADER)
{
}

