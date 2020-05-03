#include "window.h"

namespace sparky {
	namespace graphics
	{
		Window::Window(const char* title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!init())
			{
				glfwTerminate();
			}

		}

		Window::~Window()
		{
			glfwTerminate();

		}

		void windowResize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);

		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Could not initialize GLFW" << std::endl;
				return false;
			}
			

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to create GLFW Window" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, windowResize);

			return true;
		}

		



		void Window::clear() const
		{
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}



	}
}