#pragma once

#include <Windows.h>
#include "IThread.hpp"

template <typename Argument>
class WinThread : public IThread<Argument>
{
	HANDLE _internalThread;
public:
	virtual void run(int (*mainFunction)(Argument), Argument arg)
	{
		_internalThread = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(mainFunction), reinterpret_cast<LPVOID>(arg), 0, NULL);
	}

	virtual void cancel()
	{
		if (TerminateThread(_internalThread, EXIT_FAILURE) == 0)
		{
			std::stringstream ss("Could not cancel() thread, error happened in TerminateThread(), error code : ");
			ss << GetLastError();
			Logging::error(ss.str());
		}
	}

	virtual int wait()
	{
		DWORD return_code = WaitForSingleObject(_internalThread, INFINITE);
		switch (return_code)
		{
		case WAIT_ABANDONED:
			Logging::debug("I don't get why this message would show up, but this should be harmless.");
			break;
		case WAIT_OBJECT_0:
			break;
		case WAIT_TIMEOUT:
			Logging::debug("An Infinite timer just finished, if this line is written, you may have bigger problems to worry about");
			break;
		case WAIT_FAILED:
			std::stringstream ss("Could not wait() thread, error happened in WaitForSigleObject(), error code : ");
			ss << GetLastError();
			Logging::error(ss.str());
			break;
		}
		if (GetExitCodeThread(_internalThread, &return_code) == 0)
		{
			std::stringstream ss("Could not GetExitCodeThread() from thread, returning EXIT_FAILURE, error code : ");
			ss << GetLastError();
			Logging::warning(ss.str());
			return_code = EXIT_FAILURE;
		}
		if (return_code == STILL_ACTIVE)
		 {
			std::stringstream ss("Could not GetExitCodeThread() from thread because thread is still active. Returning EXIT_FAILURE.");
			Logging::warning(ss.str());
			return_code = EXIT_FAILURE;
		}
		return (return_code);
	}

	virtual ~WinThread() {}
};