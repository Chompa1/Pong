#include "game.h"
#include "menu_state.h"

int main()
{
	Game game;

	game.pushState(new MenuState(&game));
	game.gameLoop();
}