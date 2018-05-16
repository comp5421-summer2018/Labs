#include "Account.h"
#include<string>
using namespace std;

Account::Account(string accountName) :name{ accountName }
{

}
void Account::setName(string accountName)
{
    name = accountName;
}

string Account::getName()
{

    return name;
}
