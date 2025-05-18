#pragma once

#ifdef VX_PLATFORM_WINDOWS

extern Vertex::Application* Vertex::CreateApplication();
int main(int argc, char** argv) {

	Vertex::Log::Init();
	VX_CORE_WARN("Initialized Log!");
	int a = 5;
	VX_INFO("Hello! Var = {0}", a);
	
	auto app = Vertex::CreateApplication();
	app->Run();
	delete app;
}
#endif