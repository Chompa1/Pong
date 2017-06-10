#include "game.h"
#include "play_state.h"

int main()
{
	Game game;

	game.pushState(new PlayState(&game));
	game.gameLoop();
}