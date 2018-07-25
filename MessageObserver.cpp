#include "MessageObserver.hpp"

void MessageObserver::addMessage(const std::string& receiver, const Message& message) {
    messages.push_back(std::move(message));
    sendTo(receiver);
}

std::vector<Message> MessageObserver::collectMessages(const std::string& receiver) {
    for(auto msg : messages)
        Logger{}.info("MESSAGE: " + msg.content);
}

void MessageObserver::sendTo(const std::string& receiver) {
    Message newMessage = messages.back();
    if(receiver == "all")
        for(auto user : connectedUsers)
            user.second(newMessage);
}

void MessageObserver::disconnect(unsigned id) {
    connectedUsers.erase(id);
}

unsigned MessageObserver::connect(Handlers handler) {
    connectedUsers[nextID] = handler;
    return nextID++;
}
