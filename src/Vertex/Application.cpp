#include "vxpch.h"
#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"


namespace Vertex {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		MouseScrolledEvent e(5, 10);
		if (e.IsInCategory(EventCategoryApplication)) {
			VX_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput)) {
			VX_TRACE(e.ToString());
		}
		while (true);
	}
}
