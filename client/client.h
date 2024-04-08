#pragma once

#include <iostream>
#include <string>
#include "../server/server.h"


class IClient {
public:
	virtual ~IClient() {};

	virtual void update() = 0;

	//virtual void arrive() const = 0;

	//virtual void wait() const = 0;

	//virtual bool isBeingServed() const = 0;

	//virtual bool isNext() const = 0;

	//virtual int getPosition() const = 0;

	//virtual void served() const = 0;
};


class Client : public IClient {
private:
	Server &server;
	std::string id;
	int position;
	static int static_number_;

public:
	Client(Server &server) : server(server) {
		this->server.subscribe(this);
		++Client::static_number_;
		this->position = Client::static_number_;
	}

	virtual ~Client() {
		std::cout << "Goodbye, I was the client\"" << this->position << "\".\n";
	}

	void update() override {
		std::cout << "I the server I am free, Who is next?";
	}

	//void arrive() const override {

	//}

	//void wait() const override {

	//}

	//bool isBeingServed() const override {

	//}

	//bool isNext() const override {

	//}

	//int getPosition() const override {

	//}

	//void served() const override {

	//}
};