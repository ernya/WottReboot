#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glfw.h>
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
private:
	IMutex *_mutex;
	std::list<IThread<std::pair<Window &, IObject *> *> *> _loadingThreads;
	std::list<IUpdatable *> _updatableObjects;
	std::list<ADrawable *> _drawableObjects;
	VideoFlags _flags;
	std::vector<VideoMode> _modes;
	VideoMode _desktopMode;
	const Input _input;
protected:
	void addDrawable(ADrawable *drawable);
	void addUpdatable(IUpdatable *updatable);
public:
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
	void openWindow(int width = -1, int height = -1, int bpp = -1, bool isFullScreen = true) const;
	void run();
	const VideoFlags &getVideoFlags() const {return _flags;}
	VideoFlags &getVideoFlags() {return _flags;}
	void addObject(IObject *object);
void addObjectBlocking(IObject *object);
	void setClearColor(Color color) const;
};


