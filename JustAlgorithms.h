#ifndef __JUST_ALGORITHMS__
#define __JUST_ALGORITHMS__



//Bubble Sorting
void bubbleSorting(std::vector<AccountManagement>& dataSet) {
    bool swapped;
    if (dataSet.size() != 0) {
        do {
            swapped = false;
            for (int i{ 0 }; i < dataSet.size() - 1; i++) {
                if (dataSet[i].getAccountHolderName() > dataSet[i + 1].getAccountHolderName()) {
                    std::swap(dataSet[i], dataSet[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped == true);
    }
    else
    {
        std::cout << "\tDatabase has less than 2 items!\n\t\tExiting...\n";
        exit(EXIT_SUCCESS);
    }

}//end bubble sorting



//Binary Searching

int binarySearch(std::vector<AccountManagement>& vector, std::string search) {
    //License plate test ->  HXR7183
    int position = -1;
    int low = 0;
    int high = vector.size() - 1;
    int middle = (low + high) / 2;
    std::vector<std::string> tempVector;

    for (AccountManagement rec : vector) {
        tempVector.push_back(rec.getAccountHolderName());
    }
    for (int i{ 0 }; i < tempVector.size(); i++) {
        do {
            if (search == tempVector[middle]) {
                position = middle; // update position value if found
            }
            else if (search < tempVector[middle])
                high = middle - 1; // find the new high value        
            else
                low = middle + 1; // find the new low value        
            middle = (low + high) / 2; // find the middle of new search area    
        } while (low <= high && position == -1);
    }
    return position;
} //end Search()

std::vector<AccountManagement> searchingAlgorithm(std::vector<AccountManagement>& account, std::string userName)
{
    std::vector<AccountManagement> temp;
    for (int i{ 0 }; i < AccountManagement{}.getTotalAccounts(); i++)
    {
        if (account[i].getAccountHolderName() == userName)
        {
            temp.push_back(account[i]);
        }
    }
    return temp;
}

#endif
