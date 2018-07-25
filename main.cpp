#include <iostream>
#include <set>
#include <functional>

#include "MessageObserver.hpp"
#include "ControlerDispatcher.hpp"
#include "EmptyDispatcher.hpp"
#include "Component.h"
#include "ATM.hpp"
#include "ATM_fsm.hpp"
#include "Logger.hpp"

int main()
{
    std::cout << "Hello world" << std::endl;
    MessageObserver messages;
    Logger{}.info("Configuration..");
    std::shared_ptr<Dispatcher> controlerDispatcher = std::make_shared<ControlerDispatcher>(messages);
    std::shared_ptr<Component> stateMachine = std::make_shared<ATM>(messages);
    std::set<MessageId> types{
        CardInsertion,
        PinVerification,
        Withdraw,
        AccountBalance,
        CancelTransaction,
        CardEjection,
        IncorrectPin,
        CardBanned,
        LackOfFounds};

    Logger{}.info("Register Component State machine");
    controlerDispatcher->registerComponent(types, std::move(stateMachine));
    Logger{}.info("Set Empty Dispatcher..");
    std::shared_ptr<Dispatcher> emptyDispatcher = std::make_shared<EmptyDispatcher>();
    controlerDispatcher->setNextControlerDispatcher(emptyDispatcher);
    Logger{}.info("Successful machine configurate");
    Logger{}.info("Test cases");
	
    //  EJECTION CARD
    messages.addMessage("all", Message(CardInsertion, "12942"));
    Logger{}.info("");
    //  IncorrectPin CARD
    messages.addMessage("all", Message(CardInsertion, "123456"));
    messages.addMessage("all", Message(PinVerification, "0000"));
    Logger{}.info("");
    //  Get money
    messages.addMessage("all", Message(CardInsertion, "123456"));
    messages.addMessage("all", Message(PinVerification, "9876"));
    messages.addMessage("all", Message(Withdraw, "1000"));
    Logger{}.info("");
    //  incorrect get money
    messages.addMessage("all", Message(CardInsertion, "123456"));
    messages.addMessage("all", Message(PinVerification, "9876"));
    messages.addMessage("all", Message(Withdraw, "2500"));
    Logger{}.info("");
    // transaction cancel
    messages.addMessage("all", Message(CardInsertion, "123456"));
    messages.addMessage("all", Message(PinVerification, "9876"));
    messages.addMessage("all", Message(CancelTransaction, "stop"));
    Logger{}.info("");
    //  check account balance
    messages.addMessage("all", Message(CardInsertion, "123456"));
    messages.addMessage("all", Message(PinVerification, "9876"));
    messages.addMessage("all", Message(AccountBalance, "balance"));
    Logger{}.info("");

    Logger{}.info("disconnecting..");
    messages.disconnect(controlerDispatcher->getId());

    return 0;
}
