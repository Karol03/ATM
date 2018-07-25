#pragma once

#include "Component.h"
#include "Logger.hpp"
#include "ATM_fsm.hpp"
#include "StateIdle.hpp"
#include "StateProcessing.hpp"
#include "StateValidating.hpp"
#include "MessageObserver.hpp"

class ATM : public Component {
public:

    ATM(MessageObserver& mes): msg(mes)
    {
      createStatesMap();
      currentState = allStates[State::Idle];
    }

  virtual void handle(const Message& message) {
    currentState->handle(message);
  }

  virtual ~ATM() { }

private:

  void createStatesMap()
  {
     StateTransitionFunc transition = [this](State state)
     {
       this->currentState = allStates[state];
     };


     allStates[State::Idle] = std::make_shared<StateIdle>(transition, msg);
     allStates[State::Processing] = std::make_shared<StateProcessing>(transition, msg);
     allStates[State::Validating] = std::make_shared<StateValidating>(transition, msg);
  }

  std::map<State, std::shared_ptr<ATM_fsm>> allStates;
  std::shared_ptr<ATM_fsm> currentState;
  MessageObserver& msg;
};
