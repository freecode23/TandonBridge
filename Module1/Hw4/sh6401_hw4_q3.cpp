/*
Hw 4 Question 3:
Author: Sherly Hartono
Write a program that reads from the user a positive integer (in a decimal representation),
and prints its binary (base 2) representation.

Your program should interact with the user exactly as it shows in the following example: 
Enter decimal number:
76
The binary representation of 76 is 1001100

Implementation Requirements:
1. You are supposed to implement the algorithm that converts to base 2
 You should not use any string or special cout functionalities to make the conversion.
2. You are not allowed to use arrays.
*/

#include <iostream>

using namespace std;

int main()
{
    int num1, originalNum, remainder, bitMask, binary;

    cout << "Enter decimal number:" << endl;
    cin >> num1;
    originalNum = num1;
    bitMask = 1; // 1. set bit position

    while (num1 > 0)
    {
        remainder = num1 % 2;          // 2. get binary digit in this bit position
        binary += remainder * bitMask; // 3. append to our binary digit

        // 4. move position to the left
        bitMask = bitMask * 10;

        // 5. get the next number
        num1 = num1 / 2;
    };
    cout << "The binary representation of " << originalNum << " is " << binary << endl;
}