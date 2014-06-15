#pragma once

class IMutex
{
public:
	virtual void lock() = 0;
	virtual bool trylock() = 0;
	virtual void unlock() = 0;

	virtual ~IMutex() {}
};