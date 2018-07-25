#pragma once
#include<map>
#include<functional>
#include<memory>
#include <vector>

#include "MessagePort.h"
#include "Dispatcher.h"
#include "Logger.hpp"

typedef std::function<void(const Message&)> Handlers;

class MessageObserver : public Messenger {
public:
    virtual ~MessageObserver() = default;

    void addMessage(const std::string& receiver, const Message& message) override;
    std::vector<Message> collectMessages(const std::string& receiver) override;
    void sendTo(const std::string& receiver);
    void disconnect(unsigned id);
    unsigned connect(Handlers handler);

private:
  std::vector<Message> messages;
  std::map<unsigned, Handlers> connectedUsers;
  unsigned nextID{1};

};
