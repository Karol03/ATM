#pragma once

#include "ATM_fsm.hpp"

class StateProcessing : public ATM_fsm {
public:
  StateProcessing(StateTransitionFunc stateTransitionFunc,
                  MessageObserver& msg)
          : ATM_fsm(stateTransitionFunc), message(msg)
  { }

  void handle(const Message& message) override {
      checkWithdraw(message);
      checkAccountBalance(message);
      checkCancelTransaction(message);
  }

private:
    void checkWithdraw(const Message& mid);
    void checkAccountBalance(const Message& mid);
    void checkCancelTransaction(const Message& mid);

MessageObserver& message;

};
