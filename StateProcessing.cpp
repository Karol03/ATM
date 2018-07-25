#include "StateProcessing.hpp"

void StateProcessing::checkWithdraw(const Message& mid) {
    if(mid.type == Withdraw) {
        if(bank.isWidthdrawAccepted(mid.content)) {
            Logger{}.info("Take your money");
            stateTransition(State::Idle);
        } else {
            Logger{}.err("Not enough money");
            stateTransition(State::Validating);
            message.addMessage("all", Message(LackOfFounds, "ERROR lack of founds"));
        }
    }
}

void StateProcessing::checkAccountBalance(const Message& mid) {
    if(mid.type == AccountBalance) {
        Logger{}.info("Balance: " + Bank{}.getAccountBalance());
        stateTransition(State::Idle);
    }
}

void StateProcessing::checkCancelTransaction(const Message& mid) {
    if(mid.type == CancelTransaction) {
        Logger{}.info("Transaction was canceled");
        stateTransition(State::Idle);
    }
}
