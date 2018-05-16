#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<string>
using namespace std;
class Account
{
public:
    explicit Account(string);
    void setName(string accountName);
    string getName();

private:
    string name;
};

#endif // ACCOUNT_H
