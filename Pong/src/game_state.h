#include "game.h"	

class GameState
{

public:

	Game* game;

	virtual void Render(const float deltaTime) = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void HandleEvents(const float deltaTime) = 0;
};