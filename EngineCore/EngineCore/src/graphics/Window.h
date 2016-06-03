#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream> 
namespace engineCore{namespace graphics{

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

	class Window
	{
	private:
		friend struct GLFWwindow;	//friend allows objects to access private members of class
		int m_Width, m_Height; 
		const char *m_Title;	
		GLFWwindow* m_Window;
		bool m_Closed;

		static bool m_Keys[MAX_KEYS];	//static b/c we're using functions, not methods and only 1 keyboard to 1 window
		static bool m_MouseButtons[MAX_BUTTONS];
		static double mx, my;
	public:
		Window(const char *name, int width, int height);
		~Window();
		static bool isKeyPressed(int keycode);
		static bool isButtonPressed(int buttoncode);
		static void getMousePosition(double &x, double &y);
		void clear() const;
		void update();
		bool closed() const;

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
	private:
		bool init();
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
	};



}
}