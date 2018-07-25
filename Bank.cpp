#include <string>
#include "Bank.h"

bool Bank::isCardActive(const std::string& cardNumber) const
{
    if(cardNumber == "123456")
        return true;
    else
        return false;
}

bool Bank::isPinValid(const std::string& pinNumber) const
{
    if(pinNumber == "9876")
        return true;
    else
        return false;
}

bool Bank::isWidthdrawAccepted(const std::string& money) const
{
    if(std::stof(money) <= 2000.0f)
        return true;
    else
        return false;
}

std::string Bank::getAccountBalance() const
{
    return "3.41";
}
