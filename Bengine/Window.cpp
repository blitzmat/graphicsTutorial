#include "Window.h"

namespace Bengine {
	Window::Window()
	{

	}
	Window::~Window()
	{

	}
	int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
	{
		Uint32 flags = SDL_WINDOW_OPENGL;

		if (currentFlags & INVISIBLE)
		{
			flags |= SDL_WINDOW_HIDDEN;
		}
		if (currentFlags & FULLSCREEN)
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}
		if (currentFlags & BORDERLESS)
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}

		_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
		if (_sdlWindow == nullptr)
		{
			fatalError("SDL window could not be created.");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
		if (glContext == nullptr)
		{
			fatalError("SDL_GL context could not be created.");
		}

		GLenum error = glewInit();
		if (error != GLEW_OK)
		{
			fatalError("Could not initialize glewInit.");
		}

		std::printf("*** OpenGL Version: %s, ***\n", glGetString(GL_VERSION));

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

		// set VSYNC
		SDL_GL_SetSwapInterval(0);

		return 0;
	}

	void Window::swapBuffer()
	{
		// swap buffer and draw everything to the screen
		SDL_GL_SwapWindow(_sdlWindow);
	}
}