#include <iostream>
#include "SFML/Graphics.hpp"
#include "src/Application.h"
int main()
{
	Application app(900, 600, 60, false);
	app.Run();
	return 0;
}