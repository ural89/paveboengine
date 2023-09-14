#include "pvpch.h"
#include "DebugOverlayLayer.h"

namespace Pavebo
{
	DebugOverlayLayer::DebugOverlayLayer() : Layer("ImGUILayer")
	{
	}
	DebugOverlayLayer::~DebugOverlayLayer()
	{
	}
	void DebugOverlayLayer::OnAttach()
	{

		PAVEBO_CORE_TRACE(GetName());
	}
	void DebugOverlayLayer::OnDetach()
	{

	}
	void DebugOverlayLayer::OnUpdate()
	{

	}
	void DebugOverlayLayer::OnEvent(Event& event)
	{
	}
}