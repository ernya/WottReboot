#include "Color.hpp"

Color::Color() : _red(0), _blue(0), _green(0), _alpha(1.0f)
{
}

Color::Color(float red, float green, float blue, float alpha) : _red(red), _blue(blue), _green(green), _alpha(alpha)
{
}

void Color::setAlpha(float alpha)
{
	_alpha = alpha;
}

void Color::setRed(float red)
{
	_red = red;
}

void Color::setBlue(float blue)
{
	_blue = blue;
}

void Color::setGreen(float green)
{
	_green = green;
}

float Color::getAlpha() const
{
	return _alpha;
}

float Color::getGreen() const
{
	return _green;
}

float Color::getBlue() const
{
	return _blue;
}

float Color::getRed() const
{
	return _red;
}