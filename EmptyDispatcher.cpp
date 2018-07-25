#include "EmptyDispatcher.hpp"

void EmptyDispatcher::registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) {
    Logger{}.info("EmptyDispatcher->registerComponent->!_component");
}

void EmptyDispatcher::forwardMessage(const Message& message) {
    Logger{}.info("EmptyDispatcher->forwardMessage");
    Logger{}.err("Unexpected message");
}
