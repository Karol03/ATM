#pragma once
#include <string>
#include <functional>

#include "Component.h"
#include "MessageObserver.hpp"
#include "Bank.h"

enum class State {
    Idle = 1,
    Validating,
    Processing
};

typedef std::function<void (State)> StateTransitionFunc;

class ATM_fsm {
public:
  ATM_fsm(StateTransitionFunc stateTransitionFunc)
          : stateTransitionFunc(stateTransitionFunc)
          { }
   virtual void handle(const Message& message) = 0;

   virtual ~ATM_fsm() {}

   private:
     StateTransitionFunc stateTransitionFunc;

   protected:
     void stateTransition(State newState) {
       stateTransitionFunc(newState);
     }

protected:
  Bank bank;
};
