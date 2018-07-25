#include "ControlerDispatcher.hpp"

void ControlerDispatcher::registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) {
    if(!_component) {
        _component = std::move(component);
        _availableTypes = std::move(types);
    } else {
        if(!_nextControlerDispatcher)
            _nextControlerDispatcher = std::make_shared<ControlerDispatcher>();
        _nextControlerDispatcher->registerComponent(types, component);
    }
}

void ControlerDispatcher::forwardMessage(const Message& message)  {
    if(ifComponentMessageId(message))
        _component->handle(message);
    else if(_nextControlerDispatcher)
        _nextControlerDispatcher->forwardMessage(message);
}

bool ControlerDispatcher::ifComponentMessageId(const Message& message) {
    for(auto msgID : _availableTypes)
        if(msgID == message.type)
            return true;
    return false;
}
