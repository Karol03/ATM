#pragma once

#include<algorithm>
#include<memory>
#include<set>

#include "Dispatcher.h"
#include "MessageObserver.hpp"
#include "Logger.hpp"

class ControlerDispatcher : public Dispatcher {

public:
    ControlerDispatcher(MessageObserver& message) {
      ID = message.connect([&](const Message& msg) {
        ControlerDispatcher::forwardMessage(msg);
      });
    }
    ControlerDispatcher() = default;

    void registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) override;
    void forwardMessage(const Message& message) override;

private:
  bool ifComponentMessageId(const Message& message);

  std::shared_ptr<Component> _component;
  std::set<MessageId> _availableTypes;
};
