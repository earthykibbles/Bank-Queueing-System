#include <iostream>
#include <queue>
#include "client/client.h"

// Client enters the system via this point
// Checks the clients reason and allocated the client to a queue

struct Queues {
	std::queue<Client*> r1queue;
	std::queue<Client*> r2queue;
	std::queue<Client*> r3queue;
	std::queue<Client*> r4queue;
	std::queue<Client*> r5queue;
	std::queue<Client*> r6queue;
	std::queue<Client*> r7queue;
};


class Controller {
public:
	Queues qs;

	void assignQueue(Client* client) {
		if (client->reason == 0) {
			qs.r1queue.push(client);
		}
		else if (client->reason == 1) {
			qs.r2queue.push(client);
		}
		else if (client->reason == 2) {
			qs.r3queue.push(client);
		}
		else if (client->reason == 3) {
			qs.r4queue.push(client);
		}
		else if (client->reason == 4) {
			qs.r5queue.push(client);
		}
		else if (client->reason == 5) {
			qs.r6queue.push(client);
		}
		else if (client->reason == 6) {
			qs.r7queue.push(client);
		}
		else {
			std::abort;
		}
	}
};

