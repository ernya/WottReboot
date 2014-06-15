#pragma once

template<typename Argument>
class IThread
{
public:
	virtual void run(int (*mainFunction)(Argument), Argument arg) = 0;
	virtual void cancel() = 0;
	virtual int wait() = 0;
	virtual ~IThread() {}
};