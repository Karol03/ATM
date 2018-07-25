#include "StateValidating.hpp"

void StateValidating::checkPinVerification(const Message& mid) {
    if(mid.type == PinVerification) {
        Logger{}.info("Pin verification");
        if(bank.isPinValid(mid.content)) {
            Logger{}.info("Pin correct");
            stateTransition(State::Processing);
        } else {
            message.addMessage("all", Message(IncorrectPin, "ERROR incorrect pin"));
        }
    }
}

void StateValidating::checkIncorrectPin(const Message& mid) {
    if(mid.type == IncorrectPin) {
        Logger{}.info("Invalid pin");
        stateTransition(State::Idle);
    }
}

void StateValidating::checkCardBanned(const Message& mid) {
    if(mid.type == CardBanned) {
        Logger{}.err("CARD BANNED");
        stateTransition(State::Idle);
    }
}

void StateValidating::checkCardEjection(const Message& mid) {
    if(mid.type == CardEjection) {
        Logger{}.err("CARD EJECTION");
        stateTransition(State::Idle);
    }
}

void StateValidating::checkLackOfFounds(const Message& mid) {
    if(mid.type == LackOfFounds) {
        Logger{}.info("Lack of founds");
        stateTransition(State::Idle);
    }
}


