#pragma once

#include "ATM_fsm.hpp"

class StateValidating : public ATM_fsm {

public:
  StateValidating(StateTransitionFunc stateTransitionFunc,
                  MessageObserver& msg)
          : ATM_fsm(stateTransitionFunc), message(msg)
          { }

  void handle(const Message& message) override {
    checkPinVerification(message);
    checkIncorrectPin(message);
    checkCardBanned(message);
    checkCardEjection(message);
    checkLackOfFounds(message);
  }

private:
  void checkPinVerification(const Message& mid);
  void checkIncorrectPin(const Message& mid);
  void checkCardBanned(const Message& mid);
  void checkCardEjection(const Message& mid);
  void checkLackOfFounds(const Message& mid);

  MessageObserver& message;
};

//schullstel
