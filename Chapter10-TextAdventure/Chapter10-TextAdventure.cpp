// Chapter10-TextAdventure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameLoop.h"
#include "SerialisationManager.h"
#include <thread>

void RunGameThread(Game& game)
{
	game.RunGame();
}


int _tmain(int argc, _TCHAR* argv[])
{
	new SerialisationManager();
	
	Game game;
	std::thread gameThread(RunGameThread, std::ref(game));
	assert(gameThread.joinable());

	/*while (!game.HasFinished())
	{
		int x = 0;
	}*/
	gameThread.join();
	gameThread.detach();

	delete SerialisationManager::GetSingletonPtr();

	return 0;
}
