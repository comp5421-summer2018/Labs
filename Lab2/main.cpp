#include <iostream>
#include <iomanip>
#include <array>
#include "Account.h"
#include "List.h"

using namespace std;

int main()
{
    // ------------------------------------------------
    // C++ 11 Array (Not built-in C++98 array)
    // ------------------------------------------------

    // Example of an initialization list
    //array< int, 5 > n = { 32, 27, 64, 18, 95 };

    // Limitation of legacy arrays:
    // - No properties (not an object)
    // - Do not know its own size (have to pass around size)
    // - Equality and comparison operators are for pointer address, not for element equality
    array< int, 5 > n{};
    for (size_t i = 0; i < n.size(); ++i){
        n[i] = 0;
    }

    cout << "Element" << setw(13) << "Value" << endl;

    // Size_t is an unsigned integer that account for the size of the array
    // Guaranteed to be large enough to be able to express the maximum size of any array
    // https://stackoverflow.com/a/1951547
    for (size_t j = 0; j < n.size(); ++j){
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    // ------------------------------------------------
    // Account object example
    // ------------------------------------------------
    Account ob("ali");
    cout << "The account name before setName function is " << ob.getName() << endl;
    ob.setName("yanal");

    cout << "The account after setName function is " << ob.getName() << endl;


    // ------------------------------------------------
    // List example
    // ------------------------------------------------
    List l1;

    l1.AddNode(4);

    l1.AddNode(7);

    l1.AddNode(2);

    l1.PrintList();

    l1.DeleteNode(7);
    l1.PrintList();


    // ------------------------------------------------
    // End
    // ------------------------------------------------
    // For windows:
    // system("pause");

    // For mac and linux:
    system("read");

    return 0;
}
