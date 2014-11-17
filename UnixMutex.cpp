#include "UnixMutex.hpp"

UnixMutex::UnixMutex()
{
  pthread_mutex_init(&_internalMutex, NULL);
}

void UnixMutex::lock()
{
  pthread_mutex_lock(&_internalMutex);
}

bool UnixMutex::trylock()
{
  return pthread_mutex_trylock(&_internalMutex);
}

void UnixMutex::unlock()
{
  pthread_mutex_unlock(&_internalMutex);
}

UnixMutex::~UnixMutex()
{
  pthread_mutex_destroy(&_internalMutex);
}
