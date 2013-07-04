#pragma once

class Color
{
protected:
	float _red;
	float _blue;
	float _green;
	float _alpha;

public:
	Color();
	Color(float red, float green, float blue, float alpha);
	void setRed(float red);
	void setBlue(float blue);
	void setGreen(float green);
	void setAlpha(float alpha);
	float getRed() const;
	float getBlue() const;
	float getGreen() const;
	float getAlpha() const;
};