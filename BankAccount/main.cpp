#include <iostream>

#include "BankAccount.hpp"
#include "Transaction.hpp"

int main()
{
    BankAccount account = BankAccount(100);

    std::cout << account << std::endl;

    account += 300;

    std::cout << account << std::endl;

    account -= 100;

    std::cout << account << std::endl;

    account.AddTransaction(Transaction(200, true));

    std::cout << account << std::endl;
}