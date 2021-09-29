#include <algorithm>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <vector>
#include <sstream>

#include "Continue.h"
#include "NewCient.h"
#include "JustAlgorithms.h"
int AccountManagement::totalAccounts = 0;

//Sort the dataset
void bubbleSorting(std::vector<AccountManagement>& );

void UserInterface(std::vector<AccountManagement>& dataSetRecords);
int binarySearch(std::vector<AccountManagement>& vector, std::string search);
void sortingAlgorithm(std::vector<AccountManagement>&);
std::vector<AccountManagement> searchingAlgorithm(std::vector<AccountManagement>& account, std::string userName);
//void searchingAlgorithm(std::vector<AccountManagement>& account);
int accountDisable(std::vector<AccountManagement>& , std::string, std::string, std::string);
//display all clients
void allClients(std::string, std::vector<AccountManagement>& );
int main()
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 4000, 2080, FALSE);
	std::vector<AccountManagement> bankAccounts;
	//Create a local database
	AccountManagement{}.localDatabase();
	//Load user interface
    UserInterface(bankAccounts);
	
	return 0;
}


void UserInterface(std::vector<AccountManagement>& dataSetRecords) {
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
    TypeWriter("\t\t\t\t\t\[*]Banking System[*]\n\n", 20);
    int pointer = 0;
    std::vector<std::string> mainMenu = {
        "Account Management",
        "Administrative Tools","[!]Exit[!]" };
    while (true) {
        system("cls"); //clear the screen
        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
        printf("\t\t\t\t\t[*]Banking System[*]\n");
        printf("\t\t\t\t  [*]Click [Space] To Select Choice[*]\n\n");
        for (int i = 0; i < mainMenu.size(); i++) {
            if (i == pointer) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                std::cout << "\t-> "; TypeWriter(mainMenu[i], 20); std::cout << " <-\n";
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                std::cout << "\t" << mainMenu[i] << "\n";
            }
        }//end forloop

        while (true) {
            if (GetAsyncKeyState(VK_UP) != 0) {
                pointer -= 1;
                if (pointer == -1) {
                    pointer = mainMenu.size();
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0) {
                pointer += 1;
                if (pointer == mainMenu.size()) {
                    pointer = 0;
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
                switch (pointer) {
                	//Account Management Menu
                case 0: //
                {
                    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
                    TypeWriter("\t\t\t\t\t\[*]Account Management[*]\n\n", 20);
                    int accountManagementPointer = 0;
                		
                    std::vector<std::string> accountManagementMenu = { //vector to hold menu items
                    	"Client Search",
                        "Add New Client",
                        "Delete Account",
                        "Disable Account",
                        "Display All Accounts",
                    	"[!]Exit[!]"
                    };
                    while (true) {
                        system("cls"); //clear the screen
                        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
                        printf("\t\t\t\t\t[*]Account Management[*]\n");
                        printf("\t\t\t\t  [*]Click [Space] To Select Choice[*]\n\n");
                        for (int i = 0; i < accountManagementMenu.size(); i++) {
                            if (i == accountManagementPointer) {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                                std::cout << "\t-> "; TypeWriter(accountManagementMenu[i], 20); std::cout << " <-\n";
                            }
                            else {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                                std::cout << "\t" << accountManagementMenu[i] << "\n";
                            }
                        }//end forloop

                        while (true) {
                            if (GetAsyncKeyState(VK_UP) != 0) {
                                accountManagementPointer -= 1;
                                if (accountManagementPointer == -1) {
                                    accountManagementPointer = accountManagementMenu.size();
                                }
                                break;
                            }

                            else if (GetAsyncKeyState(VK_DOWN) != 0) {
                                accountManagementPointer += 1;
                                if (accountManagementPointer == accountManagementMenu.size()) {
                                    accountManagementPointer = 0;
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
                                switch (accountManagementPointer) {
                                    //Client Search
                                case 0: 
                                {
                                    while (true) {
                                        std::cout << "Sorting...\n";
                                        bubbleSorting(dataSetRecords);
                                        std::string search;
                                        system("cls"); //clear the screen
                                        std::cout << "\t\t\tType exit to Quit or back to return to main menu\n";
                                        printf("\tClient First and Last Name: ");
                                        std::cin >> search;
                                        //for (int i = 0; i < search.size(); i++) {
                                        //    search[i] = toupper(search[i]);
                                        //}
                                        if (binarySearch(dataSetRecords, search) != -1) {
                                            std::cout << "\n";
                                            std::cout << "ACCOUNT_HOLDER";
                                            std::cout << std::setw(23) << "ACCOUNT_BALANCE";
                                            std::cout << std::setw(28) << "ACCOUNT_INTEREST_RATE";
                                            std::cout << std::setw(15) << "IS_DEBIT";
                                            std::cout << std::setw(15) << "IS_CREDIT";
                                            std::cout << std::setw(20) << "ACCOUNT_STATUS";
                                            std::cout << "\n";
                                            for (int i{ 0 }; i < 1; i++) {
                                                std::cout << dataSetRecords[binarySearch(dataSetRecords, search)];
                                            }
                                        }
                                        else if (search == "EXIT") { exit(0); }
                                        else if (search == "BACK") { main(); }
                                        else {
                                            std::cout << search << " is not in the database!\n";
                                        }
                                        Sleep(1000);
                                        Continue("Press Any Key to Search Again :)");
                                        while (_getch() == 0) {
                                            break;
                                        }
                                    }
                                    main();
                                    [[fallthrough]];
                                }
                                //New Client Setup
                                case 1: 
                                {
                                    srand(time(nullptr)); //Random Seeder  // NOLINT(cert-msc51-cpp)
									createClientProfile(dataSetRecords);
									UserInterface(dataSetRecords);
                                
                                } //end New Client Setup
                                    
                                    //Delete Account
                                case 2:
	                            {
                                    std::vector<AccountManagement> database;
                                    allClients("BankAccounts.csv", database); //get accounts from database file
                                    bubbleSorting(database); //sort the vector
                                        //store location of client
                                    std::string firstName;
                                    std::string lastName;
                                    std::string dateOfBirth;
                                    std::string socialSecurity;
                                    std::cout << "\tFirst Name: ";
                                    std::cin >> firstName;
                                    std::cout << "\tLast Name: ";
                                    std::cin >> lastName;
                                    std::cout << "\tDate of Birth Name: ";
                                    std::cin >> dateOfBirth;
                                    std::cout << "\tSocial Security: ";
                                    std::cin >> socialSecurity;
                                    int clientLocation = accountDisable(database, (firstName + " " + lastName), socialSecurity, dateOfBirth);
                                    for (int i{ 0 }; i < 1; i++) {
                                        if (clientLocation != -1)
                                        {
                                        	//Delete database
                                            if (database[clientLocation].getBalance() == 0.00) {
                                                std::cout << "\tDeleting " << database[clientLocation].getAccountHolderName() << "'s account...\n";
                                                Sleep(2000);
                                                database.erase(database.begin() + clientLocation);
                                            }
                                        	else
                                            {
                                                std::cout << "\tCan not delete " << database[clientLocation].getAccountHolderName() << "'s account.\n";
                                                std::cout << "\tRemove the balance from account first! \n";
                                                std::cout << "\tReturning to main screen...";
                                                Sleep(3000);
                                            }
                                        }
                                        else {
                                            std::cout << "\tCould not find!";
                                        }
                                        //Update database
                                        AccountManagement{}.updateDatabase(database);
                                        UserInterface(dataSetRecords);
                                    }
                                }
	                            	
                                	//Disable Account
                                case 3:
	                            {
                                    std::vector<AccountManagement> database;
                                    allClients("BankAccounts.csv", database); //get accounts from database file
                                    bubbleSorting(database); //sort the vector
                                		//Vars to store clients data
									std::string firstName;
                                    std::string lastName;
                                    std::string dateOfBirth;
                                    std::string socialSecurity;
                                    std::cout << "\tFirst Name: "; std::cin >> firstName;
                                    std::cout << "\tLast Name: ";  std::cin >> lastName;
                                    std::cout << "\tDate of Birth Name: "; std::cin >> dateOfBirth;
                                    std::cout << "\tSocial Security: ";  std::cin >> socialSecurity;
                                    //store location of client

									int clientLocation = accountDisable(database, (firstName + " " + lastName), socialSecurity, dateOfBirth);
                                    for (int i{ 0 }; i < 1; i++) {
                                        if (clientLocation != -1)
                                        {
                                            database[clientLocation].setAccountStatus(false);
                                        }
                                        else {
                                            std::cout << "\tCould not find!";
                                        }
                                        //Update database
                                        
                                        AccountManagement{}.updateDatabase(database);
                                    }
	                            }
                                	
                                	//Display All Accounts
                                case 4: 
                                {
                                    std::cout << "\n";
                                    std::cout << "ACCOUNT_HOLDER";
                                    std::cout << std::setw(21) << "DATE_OF_BIRTH";
                                    std::cout << std::setw(25) << "SOCIAL_SECURITY#";
                                    std::cout << std::setw(22) << "ACCOUNT_BALANCE";
                                    std::cout << std::setw(27) << "ACCOUNT_INTEREST_RATE";
                                    std::cout << std::setw(18) << "ACCOUNT_TYPE";
                                    std::cout << std::setw(20) << "ACCOUNT_STATUS";
                                    std::cout << "\n";
                                    for (int i{ 0 }; i < 147; i++)
                                    {
                                        std::cout << "-";
                                    }
                                    std::cout << "\n";
                                    std::vector<AccountManagement> database;
                                    allClients("BankAccounts.csv", database);
                                    for (int i{ 0 }; i < database.size(); i++)
                                    {
                                        std::cout << database[i] << std::endl;
                                    }

                                    system("pause");
                                }
                                //Exit
                                case 5: 
                                {
                                    exit(EXIT_SUCCESS); //quit the program with success
                                }
                                default:
                                    break;
                                }//end switch
                            } //end return else
                        }
                    }//end main while loop
                }
	
                //Administrative Tools
                case 1: //Administrative Tools
                {
                    
                    break;
                } // end Administrative

                case 2: //Exit
                {
                    exit(EXIT_SUCCESS); //quit the program with success
                }
                default:
                    break;
                }//end switch
            } //end return else
        }
    }//end main while loop
}//end userInterface()

void allClients(std::string databaseName, std::vector<AccountManagement>& newDatabase)
{
    AccountManagement clients;

    std::fstream database(databaseName, std::ios::in);
    std::string name, account_balance, account_interest_rate,
				accountType, dateOfBirth, socialSecurity, account_status;
    std::string line;
    if (!database.is_open())
        std::cout << "\tCouldn't open the file!\n";
	if(database.is_open())
	{
        getline(database, line);
		while(getline(database, line))
		{
            std::stringstream row{ line };
            getline(row, name , ',');
            getline(row, dateOfBirth, ',');
            getline(row, socialSecurity, ',');
            getline(row, account_balance, ',');
            getline(row, account_interest_rate, ',');
            getline(row, accountType, ',');
            getline(row, account_status);

            clients.setAccountHolderName(name, "");
            clients.setDateOfBirth(dateOfBirth);
            clients.setSocialSecurityNumber(socialSecurity);
			clients.setAccountStatus(true);
            clients.setAccountType(accountType);
            for (int i{ 0 }; i < account_balance.size(); i++) {
                if (account_balance[i] == '$') 
                    account_balance.erase(i, 1);
            }
            clients.setInitialBalance(std::stod(account_balance));
			for(int i{ 0 }; i < account_interest_rate.size(); i++)
			{
                if (account_interest_rate[i] == '%')
                    account_interest_rate.erase(i, 1);
			}
            clients.setInterestRate(std::stod(account_interest_rate));
            newDatabase.push_back(clients);
		}
	}

    database.close();
}

int accountDisable(std::vector<AccountManagement>& bankAccounts, std::string accountHolder, std::string socialSecurity, std::string dateOfBirth)
{
    //Find client
    int position = -1;
    int low = 0;
    int high = bankAccounts.size() -1;
    int middle = (low + high) / 2;
    std::vector<std::string> accountNames;
    std::vector<std::string> accountSocialSecurity;
    std::vector<std::string> accountDateOfBirth;
    for (AccountManagement rec : bankAccounts) {
        accountNames.push_back(rec.getAccountHolderName());
        accountSocialSecurity.push_back(rec.getSocialSecurity());
        accountDateOfBirth.push_back(rec.getDateOfBirth());
    }
	//check for spaces
    for(int i{0}; i < accountNames.size(); i++)
    {
        while (accountNames[i].back() == ' ')
            accountNames[i].pop_back();
    }
    for (int i{ 0 }; i < accountSocialSecurity.size(); i++)
    {
        while(accountSocialSecurity[i].back() == ' ')
            accountSocialSecurity[i].pop_back();
    }
    for (int i{ 0 }; i < accountDateOfBirth.size(); i++)
    {
        while (accountDateOfBirth[i].back() == ' ')
            accountDateOfBirth[i].pop_back();
    }
    for (int i{ 0 }; i < accountNames.size(); i++) {
        std::cout << "|" << accountNames[i] << "|" << std::endl;
    }
    for (int i{ 0 }; i < accountSocialSecurity.size(); i++) {
        std::cout << "|" << accountSocialSecurity[i] << "|" << std::endl;
    }
    for (int i{ 0 }; i < accountDateOfBirth.size(); i++) {
        std::cout << "|" << accountDateOfBirth[i] << "|" << std::endl;
    }
    system("pause");
    for (int i{ 0 }; i < accountNames.size(); i++) {
        do {
            if (accountHolder == accountNames[middle] && socialSecurity == accountSocialSecurity[middle] && dateOfBirth == accountDateOfBirth[middle]) {
                position = middle; // update position value if found
            }
            else if (accountHolder < accountNames[middle] && socialSecurity < accountSocialSecurity[middle] && dateOfBirth < accountDateOfBirth[middle])
                high = middle - 1; // find the new high value        
            else
                low = middle + 1; // find the new low value        
            middle = (low + high) / 2; // find the middle of new search area    
        } while (low <= high && position == -1);
    }
    return position;
}//

