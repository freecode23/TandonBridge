//
// Created by sherly hartono on 2/11/21.
//

#include <iostream>

using namespace std;

int main()
{
    int binDigit = 0;
    int decimalNum;
    int decimalNumIter;
    cout << "Enter a decimal number: ";
    cin >> decimalNum;
    decimalNumIter = decimalNum;
    int digitPosition = 1;

    while(decimalNumIter > 0)
    {
        // get first LSB:
        binDigit += ((decimalNumIter % 2) * digitPosition);

        // next position to the right
        digitPosition *= 10;

        // get update decimalItern
        decimalNumIter = decimalNumIter /2;

    }
    cout << binDigit <<endl;
}


