#include "Transaction.hpp"

Transaction::Transaction(double amount, bool negative)
{
	this->amount = amount;
	this->negative = negative;
	date = time(0);
}

Transaction::~Transaction() { }

std::string Transaction::dateString() const
{
	char dateString[26];
	ctime_s(dateString, sizeof dateString, &date);
	return std::string(dateString);
}
