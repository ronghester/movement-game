#include "gamesession.hpp"

GameSession::GameSession() 
{
	start = new StartWindow();
}

void GameSession::launch() 
{
	start->show();
}
