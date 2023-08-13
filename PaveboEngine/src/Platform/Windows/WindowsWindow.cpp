#include "pvpch.h"
#include "WindowsWindow.h"
#include "Pavebo/Event/ApplicatoinEvent.h"
#include "Pavebo/Event/KeyEvent.h"
namespace Pavebo
{
	static bool s_GLFWInitialized = false; //it is static to initialize once

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}
	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		PAVEBO_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized) //this is static to initialize once
		{
			int success = glfwInit();

			if (success == 0)
				PAVEBO_CORE_ERROR("Could not initialize GLFW!");
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data); //m_data is custom data type. you will recieve this as a callback parameter
		SetVSync(true);
		
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height){
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowResizeEvent windowResizeEvent(width, height);
			
			data.Width = windowResizeEvent.GetWidth();
			data.Height = windowResizeEvent.GetHeight();
			data.EventCallback(windowResizeEvent);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData &data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent windowCloseEvent = WindowCloseEvent();
			data.EventCallback(windowCloseEvent);
			
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			PAVEBO_CORE_INFO(key);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}


}