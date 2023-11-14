#include "BankAccount.hpp"
#include <string>

BankAccount::BankAccount(double startingBalance)
{
	balance = startingBalance;
}

BankAccount::~BankAccount() { }

void BankAccount::AddTransaction(const Transaction& transaction)
{
	transactionHistory.push_back(transaction);

	if (transaction.negative)
	{
		balance -= transaction.amount;
	}
	else
	{
		balance += transaction.amount;
	}
}

void BankAccount::operator+=(const double amount)
{
	AddTransaction(Transaction(amount));
}

void BankAccount::operator-=(const double amount)
{
	AddTransaction(Transaction(amount, true));
}

std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount)
{
	os << "Curent balance: " << std::to_string(bankAccount.balance) << std::endl;

	for (int i = 0; i < bankAccount.transactionHistory.size(); i++)
	{
		const char sign = bankAccount.transactionHistory[i].negative ? '-' : '+';

		os << "Transaction #" << std::to_string(i) << ": " << sign <<
			" " << std::to_string(bankAccount.transactionHistory[i].amount) << "€"
			<< ", At: " << bankAccount.transactionHistory[i].dateString();
	}

	return os;
}
