#include <iostream>

using namespace std;

int modulo(int dividend, int divisor);

int main()
{
    int divisor;
    int dividend;
    cout << "enter a dividend: ";
    cin >> dividend;

    cout << "enter a divisor: ";
    cin >> divisor;

    int rem;
    rem = modulo(dividend, divisor);


    cout << "remainder is : " << rem << endl;

}

int modulo(int dividend, int divisor)
{
    if (divisor == 0)
    {
        cout << "Divisor cannot be 0";
        return 0;
    }
    // base case:
    if (dividend < divisor)
    {
        return dividend; // dividend is the remainder
    }
    else
    {
        // keep subtracting the dividend by divisor. we dont care about the quotient
        return modulo(dividend - divisor, divisor);
    }
}

// recursive
// dividend   < divisor?
// 14         > 4  X
// 14-4 = 10  > 4  X
// 10-4 = 6   > 4  X
// 6-4 =  2   < 4  YES    return 2