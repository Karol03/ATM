#pragma once

#include<memory>

#include "Dispatcher.h"
#include "MessageObserver.hpp"
#include "Logger.hpp"

class EmptyDispatcher : public Dispatcher {

public:
    EmptyDispatcher(MessageObserver& message) {
      ID = message.connect([&](const Message& msg) {
        EmptyDispatcher::forwardMessage(msg);
      });
    }
    EmptyDispatcher() = default;

    void registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) override;
    void forwardMessage(const Message& message) override;
};
