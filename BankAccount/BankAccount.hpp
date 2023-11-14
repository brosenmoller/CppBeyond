#pragma once

#include <vector>
#include <ostream>
#include "Transaction.hpp"

class BankAccount
{
public:
	BankAccount(double startingBalance);
	~BankAccount();

	double balance;
	std::vector<Transaction> transactionHistory;

	void AddTransaction(const Transaction &transaction);
	void operator += (const double amount);
	void operator -= (const double amount);

	friend std::ostream& operator << (std::ostream& os, const BankAccount& bankAccount);
};