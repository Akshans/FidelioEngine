#include "Window.h"


namespace engineCore{namespace graphics{
	void windowResize(GLFWwindow *window, int width, int height);
	
	Window::Window(const char *title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;
		init();
		//Initalize key array to false
		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
		}
	}
	Window::~Window()
	{
		glfwTerminate();	
	}
	//Make window and check if glew and glfw work
	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW" << std::endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height,m_Title, NULL,NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		if (glewInit() != GLEW_OK)	
		{
			std::cout << "Failed to initialize GlEW" << std::endl;
			return false;
		}
		std::cout << glGetString(GL_VERSION) << std::endl;
		return true;
	}
	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
	void Window::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);	//swaps the front buffer(crap rendered on screen) with back buffer(new crap that you render to)
	}

	void window_resize(GLFWwindow *window, int width, int height)	//Anything with "_" is a function, with camelcase, it's a method
	{
		glViewport(0, 0, width, height);

	}
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		if(action != GLFW_RELEASE)
			win->m_Keys[key] = true	//Happens If button gets pressed

	}


}}