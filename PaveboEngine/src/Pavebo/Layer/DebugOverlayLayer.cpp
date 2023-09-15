#include "pvpch.h"
#include "DebugOverlayLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGUIOpenGLRenderer.h"

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
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

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