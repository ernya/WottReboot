#pragma once

#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Logging.hpp"
#include "IMutex.hpp"

class WinMutex : public IMutex
{
	CRITICAL_SECTION _internalMutex; 
public:
	WinMutex();
	void lock();
	bool trylock();
	void unlock();
	~WinMutex();
};