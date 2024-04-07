#pragma once

#include <iostream>
#include <string>
#include <queue>
#include "../misc/reason.h"

class BaseClient {
private:
	std::string id;
	int position;

public:
	Reason reason;
	int timearrived = 0;
	int timequeue = 0;
	int timeserved = 0;
	int timetaken = 0;

	BaseClient(){};

	virtual ~ BaseClient(){}

	virtual void arrive() const = 0;

	void doneWaiting(int& time) {
		this->timequeue = time - this->timearrived;
	}

	void beingServed() {
		this->timeserved++;
	}

	void served(int& time) {
		this->timetaken = (int)this->timeserved + (int)this->timequeue;
		std::cout << "Time Spent in Queue: " << this->timetaken << "\n";
	}
};


class R1Client :public BaseClient {
public:
	std::queue<R1Client>& clientqueue;

	R1Client(std::queue<R1Client>& clientqueue): clientqueue(clientqueue){};

	void arrive() const override {
		clientqueue.push(*this);
	}
};

class R2Client :public BaseClient {
public:
	std::queue<R2Client>& clientqueue;
	void arrive() const override {
		clientqueue.push(*this);
	}
};

class R3Client :public BaseClient {
public:
	std::queue<R3Client>& clientqueue;
	void arrive() const override {
		clientqueue.push(*this);
	}
};

class R4Client :public BaseClient {
public:
	std::queue<R4Client>& clientqueue;

	void arrive() const override {
		clientqueue.push(*this);
	}
};

class R5Client :public BaseClient {
public:
	std::queue<R5Client>& clientqueue;
	void arrive() const override {
		clientqueue.push(*this);
	}
};

class R6Client :public BaseClient {
public:
	std::queue<R6Client>& clientqueue;
	void arrive() const override {
		clientqueue.push(*this);
	}
};


class R7Client :public BaseClient {
public:
	std::queue<R7Client>& clientqueue;

	void arrive() const override {
		clientqueue.push(*this);
	}
};








class ClientCreator {
public:
	virtual ~ClientCreator() {};
	virtual BaseClient* createClient() const = 0;


	void enterSystem() const {
		// Call the factory method to create a Product object.
		BaseClient* client = this->createClient();
		// Now, use the product.
		client->arrive();
		delete client;
	}
};


class R1ClientCreator : public ClientCreator {
public:
	BaseClient* createClient() const override {
		return new R1Client();
	}
};

class R2ClientCreator : public ClientCreator {
public:
	BaseClient* createClient() const override {
		return new R2Client();
	}
};

class R3ClientCreator : public ClientCreator {
public:
	BaseClient* createClient() const override {
		return new R3Client();
	}
};

class R4ClientCreator : public ClientCreator {
public:
	BaseClient* createClient() const override {
		return new R4Client();
	}
};

class R5ClientCreator : public ClientCreator {
public:
	BaseClient* createClient() const override {
		return new R5Client();
	}
};

class R6ClientCreator : public ClientCreator {
public:
	BaseClient* createClient() const override {
		return new R6Client();
	}
};

class R7ClientCreator : public ClientCreator {
public:
	BaseClient* createClient() const override {
		return new R7Client();
	}
};