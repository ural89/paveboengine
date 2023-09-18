#pragma once
#include "pvpch.h"
#include "Pavebo/Layer/Layer.h"
namespace Pavebo {
	class PAVEBO_API DebugOverlayLayer : public Layer
	{
	public:
		DebugOverlayLayer();
		~DebugOverlayLayer();
		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
	private:
		float m_Time = 0.0f;
	};
}