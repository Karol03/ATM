#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "Logger.hpp"

enum MessageId
{
    CardInsertion ,
    PinVerification,
    Withdraw,
    AccountBalance,
    CancelTransaction,
    CardEjection,
    IncorrectPin,
    CardBanned,
    LackOfFounds,
};

struct Message
{
    Message() = default;
    Message(MessageId id, std::string mcontent) {
      type = id;
      content = mcontent;
    }

    MessageId type;
    std::string content;
};

#endif //MESSAGE_H
