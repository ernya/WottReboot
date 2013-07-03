#include "SimpleVertexShader.hpp"
#include "ShaderTools.hpp"
#include "Global.hpp"

SimpleVertexShader::SimpleVertexShader() : AShader(ShaderTools::loadShaderFile("vs.txt"), AShader::VERTEX_SHADER)
{
}

