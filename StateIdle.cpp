#include "StateIdle.hpp"

void StateIdle::checkCardInsertion(const Message& mid) {
    if(mid.type == CardInsertion) {
        if(bank.isCardActive(mid.content)) {
            stateTransition(State::Validating);
            Logger{}.info("Card confirmed");
        } else {
            Logger{}.err("Invalid card number");
        }
    }
}

