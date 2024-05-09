#pragma once

#ifdef AST_PLATFORM_WINDOWS

extern Astro::Application* Astro::CreateApplication();

inline int main(int argc, char** argv)
{
	Astro::Log::Init();
	AST_CORE_WARN("Initialized Log!");
	const int a = 5;
	AST_INFO("Hello! Var={0}", a);

	auto app = Astro::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif
