#ifndef __UNIXMUTEX_HPP_
#define __UNIXMUTEX_HPP_

#include <iostream>
#include <sstream>
#include <pthread.h>
#include "Logging.hpp"
#include "IMutex.hpp"

class UnixMutex : public IMutex
{
  pthread_mutex_t _internalMutex;
public:
  UnixMutex();
  void lock();
  bool trylock();
  void unlock();
  ~UnixMutex();
};

#endif
