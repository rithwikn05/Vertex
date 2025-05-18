#pragma once

#ifdef VX_PLATFORM_WINDOWS

extern Vertex::Application* Vertex::CreateApplication();
int main(int argc, char** argv) {

	printf("Vertex Engine");
	auto app = Vertex::CreateApplication();
	app->Run();
	delete app;
}
<<<<<<< HEAD
=======

>>>>>>> fe90415d39d646bae8c6ad255144f877f6c804e7
#endif