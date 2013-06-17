#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

#include "VideoFlags.hpp"
#include "IUpdatable.hpp"
#include "IDrawable.hpp"
#include "VideoMode.hpp"
#include "Input.hpp"

using namespace glm;

#define VIDEO_MODES_LIMIT 100

class Window
{
private:
	std::list<IUpdatable *> _updatableObjects;
	std::list<IDrawable *> _drawableObjects;
	VideoFlags _flags;
	std::vector<VideoMode> _modes;
	VideoMode _desktopMode;
	const Input _input;
protected:
	void addDrawable(IDrawable *drawable);
	void addUpdatable(IUpdatable *updatable);
public:
	static const int OPENGL_VERSION_MAJOR = 3;
	static const int OPENGL_VERSION_MINOR = 3;
	Window(void);
	virtual ~Window(void);
	const std::list<IUpdatable *> &getUpdatables() const { return _updatableObjects; }
	const std::list<IDrawable *> &getDrawables() const { return _drawableObjects; }
	const VideoMode &getBestVideoMode() const;
	const VideoMode &getDesktopVideoMode() const;
	const std::vector<VideoMode> &getVideoModes() const;
	void openWindow(int width = -1, int height = -1, int bpp = -1, bool isFullScreen = true) const;
	void run();
	const VideoFlags &getVideoFlags() const {return _flags;}
	VideoFlags &getVideoFlags() {return _flags;}
	void addObject(IObject *object);
};


