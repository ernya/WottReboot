#ifndef __WIN_THREAD_HPP_
#define __WIN_THREAD_HPP_

#include <pthread.h>
#include "IThread.hpp"

template <typename Argument>
class UnixThread : public IThread<Argument>
{
  pthread_t _internalThread;
public:
  virtual void run(int (*mainFunction)(Argument), Argument arg)
  {
    pthread_create(&_internalThread, NULL, reinterpret_cast<void *(*)(void *)>(mainFunction), reinterpret_cast<void *>(arg));
  }

  virtual void cancel()
  {
    pthread_cancel(_internalThread);
  }

  virtual int wait()
  {
    int value;
    int ret = pthread_join(_internalThread, reinterpret_cast<void **>(&value));
    switch (ret)
      {
      case EDEADLK:
	Logging::debug("Deadlock detected");
	break;
      case EINVAL:
	Logging::debug("Invalid value when wait()");
	break;
      case 0:
	return value;
	break;
      }
    return 0;
  }

  virtual ~UnixThread() {}
};

#endif
