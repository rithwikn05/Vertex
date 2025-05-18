#include <Vertex.h>

class Sandbox : public Vertex::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Vertex::Application* Vertex::CreateApplication() {
	return new Sandbox();
}