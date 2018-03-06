#include "Game.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Game game;
	while (!game.GetWindow()->isDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
}