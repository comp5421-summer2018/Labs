#include <iostream>

using namespace std;

// Function prototypes / declarations (optional if function is declared before it is used)
int squareByValue(int);
void squareByReference(int &);

// Function definitions
int squareByValue(int x){
    return x*x;
}

void squareByReference(int &x){
    x *= x;
}

int main(int argc, char* argv[])
{
    /* ----------------------------------------
     * Basic output
     * ----------------------------------------- */
    cout << "Welcome to COMP 5421" << endl;

    /* ----------------------------------------
     * Number addition
     * ----------------------------------------- */

    int number1, number2, sum;

    cout << "Enter first number: ";
    cin >> number1;

    cout << "Enter second number: ";
    cin >> number2;

    sum = number1 + number2;
    cout << number1 << "+" << number2 << "=" << sum << endl;


    /* ----------------------------------------
     * Number conversions
     * ----------------------------------------- */

    // Implicit conversions
    short a = 300;
    int b = a;
    cout << b << endl;      // 300

    int x = 8;
    double y = x;
    cout << y << endl;      // 7

    double z = 9.4;
    int w = z;
    cout << w << endl;      // 9

    int ax = 99999999;
    short bx = ax;
    cout << bx << endl;     // -7937    since int value (typically 32 bits) is truncated down to fit into short (16 bits)

    // Explicit conversion
    int c1 = 5;
    int c2 = 2;
    cout << (double)c1/c2 << endl;  // 2.5, As long as one value is a double, result is promoted to double as well

    /* ----------------------------------------
    * Pass by reference and value
    * ----------------------------------------- */

    int k = 2;
    cout << squareByValue(k) << endl;       // 2

    squareByReference(k);
    cout << k << endl;                      // 4


    /* ----------------------------------------
    * Incrementing pointers
    * ----------------------------------------- */

    // Byte addressable
    int u = 10;
    int* u_ptr = &u;

    // Difference in addresses should be 4 assuming int stored as 4 bytes and system is byte addressable
    cout<< u_ptr << " " << ++u_ptr << endl;

    long ul = 10;
    long* ul_ptr = &ul;

    // Difference in addresses should be 8 assuming long stored as 8 bytes and system is byte addressable
    cout<< ul_ptr << " " << ++ul_ptr << endl;

    // Pause the application, Windows specific command
    // system("pause");

    return 0;
}