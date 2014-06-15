#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "VideoFlags.hpp"
#include "IUpdatable.hpp"
#include "ADrawable.hpp"
#include "VideoMode.hpp"
#include "Input.hpp"
#include "Color.hpp"

using namespace glm;

#include "IThread.hpp"
#include "IMutex.hpp"

#define VIDEO_MODES_LIMIT 100

class ADrawable;

class Window
{
public:
	enum ExecutionPriority
	{
		LOWEST,
		LOW,
		NORMAL,
		HIGH,
		HIGHEST
	};
private:
	IMutex *_mutex;
	IMutex *_mutexLoading;
	std::list<IThread<std::pair<Window &, IObject *> *> *> _loadingThreads;
	std::list<IUpdatable *> _updatableObjects;
	std::list<ADrawable *> _drawableObjects;
	VideoFlags _flags;
	std::vector<VideoMode> _modes;
	VideoMode _desktopMode;
	Input _input;
	GLFWwindow *_window;
	std::map<ExecutionPriority, std::list<std::pair<void (*)(void *), void *> > > _pendingRenderingActions;
protected:
	void addDrawable(ADrawable *drawable);
	void addUpdatable(IUpdatable *updatable);
public:
	template <typename Argument>
	void execOnRenderingThread(void (*ptr)(Argument), ExecutionPriority priority, Argument arg)
	{
		_mutexLoading->lock();
		_pendingRenderingActions[priority].push_back(std::make_pair(reinterpret_cast<void (*)(void *)>(ptr), reinterpret_cast<void *>(arg)));
		_mutexLoading->unlock();
	}

	static const int OPENGL_VERSION_MAJOR = 3;
	static const int OPENGL_VERSION_MINOR = 3;
	static const int OPENGL_VERSION_MINOR_FALLBACK = 0;
	Window(void);
	virtual ~Window(void);
	const std::list<IUpdatable *> &getUpdatables() const { return _updatableObjects; }
	const std::list<ADrawable *> &getDrawables() const { return _drawableObjects; }
	const VideoMode &getBestVideoMode() const;
	const VideoMode &getDesktopVideoMode() const;
	const std::vector<VideoMode> &getVideoModes() const;
	void openWindow(int width = -1, int height = -1, bool isFullScreen = true);
	void run();
	const VideoFlags &getVideoFlags() const {return _flags;}
	VideoFlags &getVideoFlags() {return _flags;}
	void addObject(IObject *object);
	void addObjectBlocking(IObject *object);
	void setClearColor(Color color) const;
};


