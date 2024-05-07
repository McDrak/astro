#pragma once

#ifdef AST_PLATFORM_WINDOWS

extern Astro::Application* Astro::CreateApplication();

int main(int argc, char** argv)
{
	printf("Astro Engine!\n");
	auto app = Astro::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif
