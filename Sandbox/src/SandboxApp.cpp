#include <Vertex.h>

class ExampleLayer : public Vertex::Layer {
public:
	ExampleLayer() : Layer("Example") {

	}

	void OnUpdate()	override {
		VX_INFO("ExampleLayer::Update");
	}

	void OnEvent(Vertex::Event& e) {
		VX_TRACE("{0}", e.ToString());
	}
};

class Sandbox : public Vertex::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Vertex::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Vertex::Application* Vertex::CreateApplication() {
	return new Sandbox();
}