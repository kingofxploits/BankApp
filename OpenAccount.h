#ifndef __OPENACCOUNT__
#define __OPENAACOUNT__
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
class AccountManagement{
	friend std::ostream& operator <<(std::ostream&, const AccountManagement&);
public:

	//Vars
	static int totalAccounts;

	//Methods
	AccountManagement();
	AccountManagement(std::string holder, double balance, double interestRate, std::string accountType, bool open);
	static void localDatabase();
	static void userCreation(AccountManagement& account);

	//auto balanceIncrease(AccountManagement& bankAccounts, double increase) -> void;
	auto balanceIncrease(std::vector<AccountManagement>& bankAccounts, double increase) -> void;

	auto balanceWithdraw(std::vector<AccountManagement>& bankAccounts, double decrease) -> void;

	//update Database
	void updateDatabase(std::vector<AccountManagement>& accounts);
	
	//Put hold on user
	void accountHold(AccountManagement& account);
	
	//Delete User Account
	static auto accountDelete(AccountManagement& account) -> bool;
	

	//Setters

	void setAccountHolderName(std::string fName, std::string lName);
	void setDateOfBirth(std::string birthDate);
	void setSocialSecurityNumber(std::string socialSecurity);
	void setInitialBalance(double initBalance);
	void setInterestRate(double interestRate);
	void setAccountType(std::string type);
	void setAccountStatus(bool status);
	//getters
	std::string getAccountHolderName() const;
	std::string getDateOfBirth() const;
	std::string getSocialSecurity() const;
	std::string getAccountType () const;
	//retrienve interest rate
	double getInterestRate() const;
	//Retrieve balance
	double getBalance() const;
	//Get Total Accounts
	int getTotalAccounts() const;
protected:

	std::string accountHolder{  "" }; //Client Name
	std::string holderSocialSecurityNumber{ "" }; //Client Social Security
	std::string dateOfBirth{ "" }; //Client Date of Birth
	std::string holderAccountType{""};
	
	double initialBalance{ 0 };
	double accountInterestRate{ 0 };
	double accountBalance{ 0 };

	bool isOpen{  };
	
};

#endif
