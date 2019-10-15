#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(const double &n) { interestRate = n; }
private:
	std::string owner;
	double amount;
	static double intereseRate;
	static double initRate() { return 8.0; };
};
double Account::interestRate = initRate();





















#endif
