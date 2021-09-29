#include "OpenAccount.h"
#include <utility>
#include <iomanip>
AccountManagement::AccountManagement(){}

AccountManagement::AccountManagement(std::string holder, double balance, double interestRate, std::string accountType, bool open)
	: accountHolder{ std::move(holder) }, accountBalance{ balance }, accountInterestRate{ interestRate }, holderAccountType{
		  std::move(accountType)
	  }, isOpen{ open }{ totalAccounts += 1; }

void AccountManagement::localDatabase()
{
	const std::string accountName = "BankAccounts.csv";
	std::fstream bankAccounts(accountName, std::ios::in);
	
	//Check if file is open
	if(!bankAccounts.is_open()) //if not exist create headers
	{
		bankAccounts.open(accountName, std::ios::out);
		bankAccounts << "ACCOUNT_HOLDER,";
		bankAccounts << "DATE_OF_BIRTH,";
		bankAccounts << "SOCIAL_SECURITY#,";
		bankAccounts << "ACCOUNT_BALANCE,";
		bankAccounts << "INTEREST_RATE,";
		bankAccounts << "ACCOUNT_TYPE,";
		bankAccounts << "ACCOUNT_STATUS\n";
	}
	if (bankAccounts.is_open()) //if exits exit func
		return;
	bankAccounts.close();
}

void AccountManagement::userCreation(AccountManagement& account)
{
	totalAccounts += 1;
	std::fstream bankAccounts;
	const std::string accountName = "BankAccounts.csv";
	bankAccounts.open(accountName, std::ios::app);
	if (bankAccounts.is_open())
	{
		bankAccounts << account.accountHolder << ",";
		bankAccounts << account.dateOfBirth<<",";
		bankAccounts << account.holderSocialSecurityNumber<<",$";
		bankAccounts << account.accountBalance << ",";
		bankAccounts << account.accountInterestRate << "%,";
		if (account.holderAccountType == "DEBIT")
			bankAccounts << "DEBIT" << ",";

		if (account.holderAccountType == "CREDIT")
			bankAccounts << "CREDIT" << ",";
		
		if (account.isOpen == true)
			bankAccounts << "OPENED" << "\n";
		else
			bankAccounts << "TEMPORARY HOLD" << "\n";

		
	}
	bankAccounts.close();
}


auto AccountManagement::balanceIncrease(std::vector<AccountManagement>& account, double increase) -> void
{
	if (increase > 0) {
		for (int i{ 0 }; i < getTotalAccounts(); i++) {
			account[i].accountBalance += increase;
		}
	}
}

//Withdraw from account
auto AccountManagement::balanceWithdraw(std::vector<AccountManagement>& account, double decrease) -> void
{
	if (decrease > 0)
		for (int i{ 0 }; i < getTotalAccounts(); i++) {
			account[i].accountBalance -= decrease;
		}
}


//Retrieve user balance
double AccountManagement::getBalance() const
{

	return accountBalance;
}
//Update database
void AccountManagement::updateDatabase(std::vector<AccountManagement>& accounts)
{
	//Load local Database
	localDatabase();
	const std::string accountName = "BankAccounts.csv";
	std::fstream bankAccounts(accountName, std::ios::out);
	if(!bankAccounts.is_open())
	{
		std::cout << "\tError opening database!\n";
		exit(EXIT_FAILURE); //exit program
	}
	if(bankAccounts.is_open())
	{
		bankAccounts << "ACCOUNT_HOLDER,";
		bankAccounts << "DATE_OF_BIRTH,";
		bankAccounts << "SOCIAL_SECURITY#,";
		bankAccounts << "ACCOUNT_BALANCE,";
		bankAccounts << "INTEREST_RATE,";
		bankAccounts << "ACCOUNT_TYPE,";
		bankAccounts << "ACCOUNT_STATUS\n";
		for (int i{ 0 }; i < accounts.size(); i++) {
			bankAccounts << accounts[i].accountHolder <<",";
			bankAccounts << accounts[i].dateOfBirth <<",";
			bankAccounts << accounts[i].holderSocialSecurityNumber << ",$";
			bankAccounts << accounts[i].accountBalance << ",";
			bankAccounts << accounts[i].accountInterestRate << "%,";
			if (accounts[i].holderAccountType == "DEBIT")
				bankAccounts << "  DEBIT" << ",";

			if (accounts[i].holderAccountType == "CREDIT")
				bankAccounts << "  CREDIT" << ",";
			if (accounts[i].isOpen == true)
				bankAccounts << "  OPENED" << "\n";
			else
				bankAccounts << "  TEMPORARY HOLD" << "\n";
		}
	}
	
	bankAccounts.close();
}

//Get total accounts
int AccountManagement::getTotalAccounts() const
{
	return totalAccounts;
}

//put user on hold
void AccountManagement::accountHold(AccountManagement& account)
{
}


//Needs Work
auto AccountManagement::accountDelete(AccountManagement& account) -> bool
{return false;}



void AccountManagement::setAccountHolderName(std::string fName, std::string lName)
{
	accountHolder = (fName + " " + lName);
}

void AccountManagement::setDateOfBirth(std::string birthDate)
{dateOfBirth = birthDate;}

void AccountManagement::setSocialSecurityNumber(std::string socialSecurity)
{holderSocialSecurityNumber = socialSecurity;}

void AccountManagement::setInitialBalance(double initBalance)
{
	this -> initialBalance = initBalance;
	this -> accountBalance = initialBalance;
}

void AccountManagement::setInterestRate(double interestRate)
{accountInterestRate = interestRate;}

void AccountManagement::setAccountType(std::string type)
{
	if (type == "CREDIT" || type == "credit" || type == "Credit")
		{holderAccountType = "CREDIT";}
	if (type == "DEBIT" || type == "Debit" || type == "debit")
		{holderAccountType = "DEBIT";}
}

void AccountManagement::setAccountStatus(bool status)
{
	if(status == true)
		{isOpen = true;}
	else { isOpen = false; }
}

std::string AccountManagement::getAccountHolderName() const
{
	return accountHolder;
}


std::string AccountManagement::getDateOfBirth() const
{return dateOfBirth;}
std::string AccountManagement::getSocialSecurity() const
{return holderSocialSecurityNumber;}

std::string AccountManagement::getAccountType() const
{
	return holderAccountType;
}

double AccountManagement::getInterestRate() const
{
	return accountInterestRate;
}

std::ostream& operator <<(std::ostream& output, const AccountManagement& rec) {

	output << "" << rec.accountHolder<<"\t";
	output << "\t     " << rec.dateOfBirth << "\t";
	output << "    " << rec.holderSocialSecurityNumber<<"\t\t";
	output << "   $" << rec.accountBalance << "\t\t\t";
	output << "" << rec.accountInterestRate << "%\t\t\t";
	output << "   " << rec.holderAccountType << "";

	if(rec.isOpen == true)
		output << "\t     OPENED" << "";
	else
		output << "\t     CLOSED" << "";
	
	return output;
}


