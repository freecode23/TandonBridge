/*
Hw4 Question 2:	
Author: Sherly Hartono
Write a program that reads from the user a
(decimal) number, and prints it’s representation in the simplified Roman numerals system.
I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Rules:
1. The digits form a monotonically non-increasing sequence.
   That is the value of each digit is less than or equal to the value of the digit that came before it.
   For example, DLXXVI is a monotonically non-increasing sequence of Roman digits, but XIV is not.
2. There is no limit on the number of times that ‘M’ can appear in the number.
‘D’, ‘L’ and ‘V’ can each appear at most one time in the number.
‘C’, ‘X’ and ‘I’ can each appear at most four times in the number.

Your program should interact with the user exactly as
it shows in the following example:
Enter decimal number:
147
147 is CXXXXVII
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int decimalNum;
    cout << "Enter decimal number: ";
    cin >> decimalNum;

    // For every numerals we do:
    // Step1:
    // Do integer division to get the number of 1000s, 500s, etc.
    // e.g 67 / 50 = 1 (no floating points)
    // we get 1 of 50s

    // Step 2:
    // Do modulo to get the remaining digit: e.g 167 % 100 = 67
    // 740 % 500 = 240

    // 1. get number of M , 1000s
    int numberOfM = decimalNum / 1000;
    // cout << "1000s M: " << numberOfM << endl;

    int remainder = decimalNum % 1000;
    // cout << "remainder " << remainder << endl;

    // 2. get number of D , 500s
    int numberOfD = remainder / 500;
    // cout << "\n500s D: " << numberOfD << endl;

    remainder = remainder % 500;
    // cout << "remainder " << remainder << endl;

    // 3. get number of C , 100s
    int numberOfC = remainder / 100;
    // cout << "\n100s C: " << numberOfC << endl;

    remainder = remainder % 100;
    // cout << "remainder " << remainder << endl;

    // 4. get number of L , 50s
    int numberOfL = remainder / 50;
    // cout << "\n50s L: " << numberOfL << endl;

    remainder = remainder % 50;
    // cout << "remainder " << remainder << endl;

    // 5. get number of X , 10s
    int numberOfX = remainder / 10;
    // cout << "\n10s X: " << numberOfX << endl;

    remainder = remainder % 10;
    // cout << "remainder " << remainder << endl;

    // 6. get number of V , 5s
    int numberOfV = remainder / 5;
    // cout << "\n5s V: " << numberOfV << endl;

    remainder = remainder % 5;
    // cout << "remainder " << remainder << endl;

    // 7. get number of I , 1s
    int numberOfI = remainder / 1;
    // cout << "\n1s I: " << numberOfI << endl;

    remainder = remainder % 1;
    // cout << "remainder " << remainder << endl;

    cout << decimalNum << " is ";

    for(int i = 1; i <= numberOfM ; i++)
    {
        cout << "M";
    }
    for(int i = 1; i <= numberOfD ; i++)
    {
        cout << "D";
    }
    for(int i = 1; i <= numberOfC ; i++)
    {
        cout << "C";
    }
    for(int i = 1; i <= numberOfL ; i++)
    {
        cout << "L";
    }
    for(int i = 1; i <= numberOfX ; i++)
    {
        cout << "X";
    }
    for(int i = 1; i <= numberOfV ; i++)
    {
        cout << "V";
    }
    for(int i = 1; i <= numberOfI ; i++)
    {
        cout << "I";
    }
    cout << endl;
}