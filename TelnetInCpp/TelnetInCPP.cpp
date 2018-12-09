#include "stdafx.h"
#include "ServerGame.h"
#include "ClientGame.h"
#include <process.h>

void serverLoop(void *);
void clientLoop(void);

ServerGame * server;
ClientGame * client;

int main()
{

	server = new ServerGame();

	_beginthread(serverLoop, 0, (void*)12);

	client = new ClientGame();

	clientLoop();
}

void serverLoop(void * arg)
{
	while (true)
	{
		server->update();
	}
}

void clientLoop()
{
	while (true)
	{
		client->update();
	}
}
