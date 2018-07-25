#pragma once

#include <string>
#include <vector>
#include "Message.h"

class Messenger
{
public:
	virtual ~Messenger() = default;

	virtual void addMessage(const std::string& receiver, const Message& message) = 0;
	virtual std::vector<Message> collectMessages(const std::string& receiver) = 0;
	// send - disconnect - connect
	//onMessageReceived
};
