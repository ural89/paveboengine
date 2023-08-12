#pragma once

#include "pvpch.h"

#include "Pavebo/Core.h"
#include "Pavebo/Event/Event.h"

namespace Pavebo
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Pavebo Engine",
			unsigned int width = 1280,
			unsigned int height = 720) : Title(title), Width(width), Height(height)
		{

		}
	};

	//interface for api

	/// <summary>
	/// staticruntime "on"
	/// runtime "Release"
	/// add these lines to glfw premake file to compile!!!!
	/// </summary>
	class PAVEBO_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}
		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}

