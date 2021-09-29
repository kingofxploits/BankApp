#ifndef __NEWCLIENT__
#define __NEWCLIENT__
#include <Windows.h>
#include <vector>
#include <limits>
#include <iostream>
#include "Typewriter.h"
#include "OpenAccount.h"

#define MAXLIMIT
std::string firstName();
std::string lastName();
std::string dateOfBirth();
std::string socialSecurity();
std::string accountType();

auto initialBalance() -> double;
auto interestRate() -> double;
void createClientProfile(std::vector<AccountManagement>& bankAccounts)
{
	srand(time(nullptr));
	system("cls");
			//Random names client data
	//std::string const randomFirstNamesArray[5] = { "Luis", "John", "Will","Matt","Leo"};
	//std::string const randomLastNamesArray[5] = { "Redfield" ,"Lawless", "Michaelson", "Dipney","Kent"};
	//std::string const randomSocialSecuritiesArray[5] = {"104021818", "023027155", "123034254", "098902342","989762342"};
	//std::string const randomDateOfBirthsArray[5] = { "June 19 2000", "January 01 1990", "October 10 1997", "December 12 1990","August 28 1993" };
	//int randomIntForArrays = (0 + rand() % 4);

	bool accountStatus = true;

	std::vector<AccountManagement> idk; //vector to hold temporary objects
	int randomValue = (0 + rand() % 1999);
	std::string randomCharacters;
	char randomChar;
	for (int i = 0; i < 10; i++)
	{
		randomChar = ((rand() % 25) + 'A');
		randomCharacters += std::toupper(static_cast<char>(randomChar));
	}

	for (int i{ 0 }; i < 2000; i++)
	{
		AccountManagement a; //Temporary object
		idk.push_back(a); // Add temporary objects to vector
	}

	AccountManagement newClient;
	newClient = idk[randomValue];
		//Get User Info
	
	std::string first_name;
	first_name = firstName();
	
	std::string last_name;
	last_name = lastName();

	std::string date_of_birth;
	date_of_birth = dateOfBirth();

	std::string social_security;
	social_security = socialSecurity();

	std::string account_type;
	account_type = accountType();

	double initial_balance{ 0.00 };
	if(account_type == "debit" || account_type == "Debit" || account_type == "DEBIT")
		initial_balance = initialBalance();

	double interest_rate{ 0.00 };
	interest_rate = interestRate();
		//Set Account Values
	newClient.setAccountHolderName(first_name, last_name);
	newClient.setDateOfBirth(date_of_birth);
	newClient.setSocialSecurityNumber(social_security);
	newClient.setAccountType(account_type);
	newClient.setInitialBalance(initial_balance);
	newClient.setInterestRate(interest_rate);
	newClient.setAccountStatus(accountStatus);

	int mainSubPointer = 0; //keep track of user selection
	std::vector<std::string> mainSubMenu = { "YES", "NO" }; //user selection options
	while (true) {
		system("cls"); //clear the screen
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
		//printf("\t\t\t\t\t[*]Banking System[*]\n");
		printf("\t\t\t\t\t[*]Click [Space] To Select Choice[*]\n");
		//Display information
		std::cout << "\t\tIs the information bellow correct?\n";
		
		std::cout << "\tCLIENT NAME: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << newClient.getAccountHolderName() << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		std::cout << "\tDATE OF BIRTH: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << newClient.getDateOfBirth() << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		std::cout << "\tSOCIAL SECURITY NUMBER: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << newClient.getSocialSecurity() << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		std::cout << "\tACCOUNT TYPE: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << newClient.getAccountType() << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		if (newClient.getAccountType() == "DEBIT") {
			std::cout << "\tINITIAL BALANCE: $";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			std::cout << newClient.getBalance() << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		
		std::cout << "\tACCOUNT INTEREST RATE: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << newClient.getInterestRate() << "%" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		for (int i = 0; i < mainSubMenu.size(); i++) {
			if (i == mainSubPointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				std::cout << "\t-> "; TypeWriter(mainSubMenu[i], 20); std::cout << " <-\n";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				std::cout << "\t" << mainSubMenu[i] << "\n";
			}
		}//end forloop
		while (true) {
			if (GetAsyncKeyState(VK_UP) != 0) {
				mainSubPointer -= 1;
				if (mainSubPointer == -1) {
					mainSubPointer = mainSubMenu.size();
				}
				break;
			}

			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				mainSubPointer += 1;
				if (mainSubPointer == mainSubMenu.size()) {
					mainSubPointer = 0;
				}
				break;
			}

			else if (GetAsyncKeyState(VK_ESCAPE) != 0) {
				system("cls"); //clear the screen
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
				TypeWriter("\tExiting Now...\n", 20);
				exit(0);
			}
			else if (GetAsyncKeyState(VK_SPACE) != 0) {
				switch (mainSubPointer) {
				case 0: //YES
				{
					//Create new user
					AccountManagement::userCreation(newClient);
					bankAccounts.push_back(newClient);

					return;
				}
				case 1: //NO
				{
					//Display Selection Menu
					int subPointer = 0;
					std::vector<std::string> subMenu = { "FIRST_NAME", "LAST_NAME",
														 "DATE_OF_BIRTH","SOCIAL_SECURITY_NUMBER" };
					subMenu.emplace_back("ACCOUNT_TYPE");
					if (newClient.getAccountType() == "DEBIT")
						subMenu.emplace_back("INITIAL_BALANCE");
					subMenu.emplace_back("ACCOUNT_INTEREST_RATE");
					while (true) {
						system("cls"); //clear the screen
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
						//printf("\t\t\t\t\t[*]Banking System[*]\n");
						printf("\t\t\t\t  [*]Click [Space] To Select Choice[*]\n\n");
						for (auto i = 0; i < subMenu.size(); i++) {
							if (i == subPointer) {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
								std::cout << "\t-> "; TypeWriter(subMenu[i], 20); std::cout << " <-\n";
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
								std::cout << "\t" << subMenu[i] << "\n";
							}
						}//end forloop
						while (true) {
							if (GetAsyncKeyState(VK_UP) != 0) {
								subPointer -= 1;
								if (subPointer == -1) {
									subPointer = subMenu.size();
								}
								break;
							}

							else if (GetAsyncKeyState(VK_DOWN) != 0) {
								subPointer += 1;
								if (subPointer == subMenu.size()) {
									subPointer = 0;
								}
								break;
							}

							else if (GetAsyncKeyState(VK_ESCAPE) != 0) {
								system("cls"); //clear the screen
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
								TypeWriter("\tExiting Now...\n", 20);
								exit(0);
							}

							else if (GetAsyncKeyState(VK_SPACE) != 0) {
								switch (subPointer) {
								case 0: //Change first name
								{
									first_name = firstName();
									newClient.setAccountHolderName(first_name, last_name);
									AccountManagement::userCreation(newClient);
									bankAccounts.push_back(newClient);
									return;
								}
								case 1: //Change last Name
								{
									last_name = lastName();
									newClient.setAccountHolderName(first_name, last_name);
									AccountManagement::userCreation(newClient);
									bankAccounts.push_back(newClient);
									return;
								}
								case 2: //change date of birth
								{
									date_of_birth = dateOfBirth();
									newClient.setDateOfBirth(date_of_birth);
									AccountManagement::userCreation(newClient);
									bankAccounts.push_back(newClient);
									return;
								}
								case 3: //change social security
								{
									social_security = socialSecurity();
									newClient.setSocialSecurityNumber(social_security);
									AccountManagement::userCreation(newClient);
									bankAccounts.push_back(newClient);
									return;
								}
								case 4: //change account type
								{
									account_type = accountType();
									newClient.setAccountType(account_type);
									AccountManagement::userCreation(newClient);
									bankAccounts.push_back(newClient);
									return;
								}
								case 5: //Initial balance
								{
									if (newClient.getBalance() != 0) {

										initial_balance = initialBalance();
										newClient.setInitialBalance(initial_balance);
										AccountManagement::userCreation(newClient);
										bankAccounts.push_back(newClient);
									}
									return;
									
								}
								case 6: //Interest rate
								{
									interest_rate = interestRate();
									newClient.setInterestRate(interest_rate);
									AccountManagement::userCreation(newClient);
									bankAccounts.push_back(newClient);
									return;
								}
								default:
									break;

								} //end main while loop of second menu

							} //end else if
						}
					}
				} //end NO CASE

				default:
					break;

				} //end main while loop of second menu

			} //end else if
		}
	}
}

//User Profile

std::string firstName()
{
		//First Name
	std::string name;
	std::cout << "\tEnter First Name: ";
	getline(std::cin >> std::ws, name);

	//remove any white spaces
	for (int i{ 0 }; i < name.size(); i++)
		if (name[i] == ' ')
			name.erase(name.begin() + i);
	
		//Name validation
	for (int i{ 0 }; i < name.size(); i++) {
		while (name.size() > 15 || name.size() < 2 || !isalpha(name[name.begin(), i]))
		{ //beging while loop
			if (name.size() < 2)
				std::cout << "\tFirst name should be longer than 2 characters!\n";
			if (name.size() > 15)
				std::cout << "\tFirst name should be less than 15 characters!\n";


			if (!isalpha(name[name.begin(), i]))
				std::cout << "\tFirst name should only contain alphabetic letters!\n";
			std::cout << "\tEnter First Name: ";
			getline(std::cin >> std::ws, name);
		} //end while loop
	}
		//Make first letter uppercase
	for (int i{ 0 }; i < name.size(); i++) {
		if (isupper(name[0]) == 0)
			std::transform(name.begin(), name.end() - name.size() + 1, name.begin(), ::toupper);
	}
	return name;
}

std::string lastName()
{
		//Last Name
	std::string name{""};
	std::cout << "\tEnter Last Name: ";
	getline(std::cin , name);
	
	//remove any white spaces
	for (int i{ 0 }; i < name.size(); i++)
		if (name[i] == ' ')
			name.erase(name.begin() + i);
	
		//Name validation
	for (int i{ 0 }; i < name.size(); i++) {
		while (name.size() > 15 || name.size() < 2 || !isalpha(name[name.begin(), i]))
		{ //beging while loop
			if (name.size() < 2)
				std::cout << "\tLast name should be longer than 2 characters!\n";
			if (name.size() > 15)
				std::cout << "\tLast name should be less than 15 characters!\n";


			if (!isalpha(name[name.begin(), i]))
				std::cout << "\tLast name should only contain alphabetic letters!\n";
			std::cout << "\tEnter Last Name: ";
			getline(std::cin, name);
		} //end while loop
	}
		//Make first letter uppercase
	for (int i{ 0 }; i < name.size(); i++) {
		if (isupper(name[0]) == 0)
			std::transform(name.begin(), name.end() - name.size() + 1, name.begin(), ::toupper);
	}
	return name;
}

//Date of Birth
std::string dateOfBirth() {
	std::string date_of_birth;
	std::cout << "\tEnter Date of Birth ->(mm/dd/yyyy): ";
	getline(std::cin ,date_of_birth);
	
		//remove any white spaces
	for (int i{ 0 }; i < date_of_birth.size(); i++)
		if (date_of_birth[i] == ' ')
			date_of_birth.erase(date_of_birth.begin() + i);
	
		//Check Date of Birth Validation
	while (date_of_birth.size() > 10 || date_of_birth.size() < 10
		|| date_of_birth[2] != '/' || date_of_birth[5] != '/'    ||
		!isdigit(date_of_birth[0]) || !isdigit(date_of_birth[1]) ||
		!isdigit(date_of_birth[3]) || !isdigit(date_of_birth[4]) ||
		!isdigit(date_of_birth[6]) || !isdigit(date_of_birth[7]) ||
		!isdigit(date_of_birth[8]) || !isdigit(date_of_birth[9]))
	{ //begin while loop
		std::cout << "\tPlease follow the guidelines!\n";
		std::cout << "\tEnter Date of Birth ->(mm/dd/yyyy): ";
		getline(std::cin, date_of_birth);
		if (date_of_birth.size() == 10 && isdigit(date_of_birth[0]) &&
			isdigit(date_of_birth[1])  && isdigit(date_of_birth[3]) &&
			isdigit(date_of_birth[4])  && isdigit(date_of_birth[6]) &&
			isdigit(date_of_birth[7])  && isdigit(date_of_birth[8]) &&
			isdigit(date_of_birth[9]))
			break;
	} //end while loop
	return date_of_birth;
}

//Social Security
std::string socialSecurity() {
	
	std::string social_security;
	
	std::cout << "\tEnter Social Security Number ->(000-00-0000): ";
	getline(std::cin, social_security);
	
		//remove any white spaces
	for (int i{ 0 }; i < social_security.size(); i++)
		if (social_security[i] == ' ')
			social_security.erase(social_security.begin() + i);
	
			//Social Security Validating
	while (social_security.size() > 11 || social_security.size() < 11 || 
		social_security[3] != '-' || social_security[6] != '-' ||
		!isdigit(social_security[0]) || !isdigit(social_security[1]) ||
		!isdigit(social_security[2]) || !isdigit(social_security[4]) ||
		!isdigit(social_security[5]) || !isdigit(social_security[7]) ||
		!isdigit(social_security[8]) || !isdigit(social_security[10]) ||
		!isdigit(social_security[9]))
	{ //beging while loop
		if (social_security[3] != '-' || social_security[6] != '-')
			std::cout << "\tPlease follow the guidelines!\n";
		std::cout << "\tEnter Social Security Number ->(000-00-0000): ";
		getline(std::cin, social_security);
		if (social_security.size() == 11 && isdigit(social_security[0]) && 
			isdigit(social_security[1])  && isdigit(social_security[2]) && 
			isdigit(social_security[4])  && isdigit(social_security[5]) && 
			isdigit(social_security[7])  && isdigit(social_security[8]) && 
			isdigit(social_security[10]) && isdigit(social_security[9]))
			break;
		
	} // end while loop

	return social_security;
}
//Account Type
std::string accountType() {
	std::string account_type;
	while (true) {
		std::cout << "\tPlease enter [debit OR credit]: ";
		getline(std::cin, account_type);
		if (account_type == "debit" || account_type == "Debit" || account_type == "DEBIT"
			|| account_type == "credit" || account_type == "Credit" || account_type == "CREDIT")
			break;
	}
		//Remove any whitespaces
	for (int i{ 0 }; i < account_type.size(); i++)
		if (account_type[i] == ' ')
			account_type.erase(account_type.begin() + i);
	
	return account_type;
}
//Initial balance
double initialBalance() {
	double initial_balance;
	std::cout << "\tEnter Initial Balance: ";
	std::cin >> initial_balance;
	while (!std::cin.good() || initial_balance < 25)
	{
		if (initial_balance < 25)
			std::cout << "\tInitial balance must be at least $25!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
		std::cout << "\tEnter Initial Balance: ";
		std::cin >> initial_balance;

	}
	return initial_balance;
}
//Interest Rate
double interestRate() {
	double interest_rate;
	std::cout << "\tEnter Interest Rate: "; std::cin >> interest_rate;
	while (!std::cin.good() || interest_rate <= 0.0)
	{
		std::cout << "\tInterest rate must be greater than 0!\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max MAXLIMIT(), '\n');
		std::cout << "\tEnter Interest Rate: ";
		std::cin >> interest_rate;
	}
	return interest_rate;
}
#endif
