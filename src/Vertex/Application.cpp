#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Vertex {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			VX_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput)) {
			VX_TRACE(e.ToString());
		}
		while (true);
	}
}
