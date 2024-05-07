namespace Astro
{
	__declspec(dllimport) void Print();
}

int main()
{
	Astro::Print();
	return 0;
}
