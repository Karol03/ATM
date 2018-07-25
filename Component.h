#ifndef COMPONENT_H
#define COMPONENT_H

#include "Message.h"

class Component
{
public:
    virtual ~Component() = default;

    virtual void handle(const Message& message) = 0;
};


#endif //COMPONENT_H
