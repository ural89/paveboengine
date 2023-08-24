#pragma once
#include "Core.h"
#include "Event/Event.h"
#include <string>
namespace Pavebo {

	class PAVEBO_API Layer
	{
		Layer(const std::string& name = "Layer");
		virtual void OnAttach(){}
		virtual void OnDetach(){}
		virtual void OnUpdate(){}
		virtual void OnEvent(Event& event){}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}