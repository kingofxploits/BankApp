#ifndef __LOCALDATABASE__
#define __LOCALDATABASE__
#include "OpenAccount.h"
class LocalDatabase
{
public:
	LocalDatabase();
	std::vector<AccountManagement> loadDatabase();
private:

protected:
};

#endif
