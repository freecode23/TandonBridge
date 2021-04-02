#include <iostream>

using namespace std;
// check if all digits are even integers

int main()
{
    int n,LSB;
    cout << "Enter an integer n: " << endl;
    cin >> n;

    // iterate through the each digit while number after division is still greater than 0
    while(n > 0)
    {
        LSB = n % 10; // give you the LSB

        cout << LSB <<endl;

        n = n /10; // give you the front remaining digits
    }

}