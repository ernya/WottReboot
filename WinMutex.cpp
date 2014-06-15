#include "WinMutex.hpp"

WinMutex::WinMutex()
{
	InitializeCriticalSection(&_internalMutex);
}

void WinMutex::lock()
{
	EnterCriticalSection(&_internalMutex);
}

bool WinMutex::trylock()
{
	return (TryEnterCriticalSection(&_internalMutex));
}

void WinMutex::unlock()
{
	LeaveCriticalSection(&_internalMutex);
}

WinMutex::~WinMutex()
{
	DeleteCriticalSection(&_internalMutex);
}