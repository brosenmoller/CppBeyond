#pragma once

#include <ctime>
#include <string>

class Transaction
{
public:
	Transaction(double amount, bool negative = false);
	~Transaction();

	double amount;
	time_t date;
	bool negative;

	std::string dateString() const;
};