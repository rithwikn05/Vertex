#pragma once

#ifdef VX_PLATFORM_WINDOWS

extern Vertex::Application* Vertex::CreateApplication();
int main(int argc, char** argv) {

	printf("Vertex Engine");
	auto app = Vertex::CreateApplication();
	app->Run();
	delete app;
}
#endif