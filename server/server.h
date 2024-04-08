#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include "../client/client.h"

class IServer {
public:
	virtual ~IServer() {};

	virtual void subscribe(IClient *client) = 0;
	virtual void unsubscribe(IClient *client) = 0;
	virtual void notify() = 0;

	virtual void callNext() = 0;
	/*virtual void serving() = 0;
	virtual void doneServing() = 0;*/
};


class Server : public IServer {
public:
	virtual ~Server() {
		std::cout << "Goodbye, I was the Subject.\n";
	}

	void subscribe(IClient *client) override {
		clients_queue.push_back(client);
	}

	void unsubscribe(IClient *client) override {
		clients_queue.remove(client);
	}

	void notify() override {
		std::list<IClient*>::iterator iterator = clients_queue.begin();
		while (iterator != clients_queue.end()) {
			(*iterator)->update();
			++iterator;
		}
	}

	void callNext() override {
		notify();
	}
private:
	std::list<IClient*> clients_queue;

};