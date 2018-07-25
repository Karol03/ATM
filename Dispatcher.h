#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Message.h"
#include "Component.h"
#include <set>

class Dispatcher
{
public:
    virtual ~Dispatcher() = default;

    virtual void registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) = 0; //how about reference instead of shared_ptr?
    virtual void forwardMessage(const Message& message) = 0;
    virtual void setId(unsigned i) final { ID = i; }
    virtual unsigned getId() final { return ID; }
    //
    virtual void setNextControlerDispatcher(std::shared_ptr<Dispatcher> nextDispatcher) final {
      if(_nextControlerDispatcher)
        _nextControlerDispatcher->setNextControlerDispatcher(nextDispatcher);
      else
        _nextControlerDispatcher = nextDispatcher;
    }
protected:
    unsigned ID{};
    std::shared_ptr<Dispatcher> _nextControlerDispatcher;
};

#endif //DISPATCHER_H
