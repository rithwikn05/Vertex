#include "vxpch.h"
#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
//#include "Core.h"

#include <../vendor/GLFW/include/GLFW/glfw3.h>


namespace Vertex {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispather(e);
		dispather.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		VX_CORE_TRACE("{0}", e.ToString());
	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}
