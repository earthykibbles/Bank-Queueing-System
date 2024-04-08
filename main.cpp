#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include "client/client.h"
#include "server/server.h"
#include "misc/reason.h"

int main()
{
	Server* server = new Server;

	for (int i = 0; i < 10; i++) {
		Client* client = new Client(*server);
	}

	server->callNext();

}