#pragma once

#include "ATM_fsm.hpp"

class StateIdle : public ATM_fsm {

public:
  StateIdle(StateTransitionFunc stateTransitionFunc,
            MessageObserver& msg)
          : ATM_fsm(stateTransitionFunc), message(msg)
  { }

  void handle(const Message& message) override {
      checkCardInsertion(message);
  }

private:
    void checkCardInsertion(const Message& mid);

    MessageObserver& message;
};
