#pragma once
#include "pvpch.h"
#include "Pavebo/Layer/Layer.h"
namespace Pavebo {
	class DebugOverlayLayer : public Layer
	{
	public:
		DebugOverlayLayer(){}
		void OnAttach() override { PAVEBO_CORE_TRACE("Attached layer"); };
		void OnDetach() override {};
		void OnUpdate() {}
		void OnEvent(Event& event) {}
	};
}