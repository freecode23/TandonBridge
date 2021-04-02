/*
Author: Sherly Hartono
Question 4:
Hw3 
Define the following constants:
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

Write a program that asks the user to enter a Real number,
then it asks the user to enter the method by which they want to round that number
(floor, ceiling or to the nearest integer). The program will then print the rounded result.
Your program should interact with the user exactly as it shows in the following example:
Please enter a Real number:
4.78
Choose your rounding method:
1. Floor round
2. Ceiling round
3. Round to the nearest whole number
2
5

Implementation requirements:
1. Use a switch statement.
2. You are not allowed to include and use the math library.
*/

#include <iostream>
#include <string>

using namespace std;
const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main()
{
    float aNumber;
    int choice;

    cout << "Please enter a real number: \n";
    cin >> aNumber;

    cout << "Choose your rounding mehod: " << endl;
    cout << "1. Floor round\n2. Ceiling round\n3. Round to the nearest whole number\n";

    cin >> choice;
    float decNeg = -1 * (aNumber - int(aNumber)); // get decimal point in positive form
    float decPos = (aNumber - int(aNumber));      // get decimal point in positive form
    // 1. if the number entered are negative:
    if (aNumber < 0)
    {
        switch (choice)
        {
        // casting a floating point number to integer will round it 'down' to the nearest integer
        case FLOOR_ROUND:
            // (int)-4.5 becomes -4
            cout << (int)aNumber - 1 << endl;
            break;

        case CEILING_ROUND:
            // get decimal

            if (decNeg == 0) // if there is no decimal just return this number
            {
                cout << aNumber << endl;
            }
            else // else return the ceiling
            {
                cout << "ceiling of " << aNumber << " is: ";
                cout << int(aNumber) << endl;
            }
            break;

        case ROUND:
            if (decNeg >= 0.5)
            {
                cout << (int)aNumber - 1 << endl; //round down
            }
            else
            {
                cout << (int)aNumber << endl; // round up
            }
            break;
        }
    }
    else // 2. If the number entered is positive or 0
    {
        switch (choice)
        {
        case FLOOR_ROUND:
            cout << (int)aNumber << endl;
            break;

        case CEILING_ROUND:
            if (decPos == 0)
            {
                cout << aNumber << endl;
            }
            else
            {
                cout << (int)aNumber + 1 << endl;
            }
            break;

        case ROUND:
            float dec = aNumber - int(aNumber);
            if (dec >= 0.5)
            {
                cout << (int)aNumber + 1 << endl; //round up
            }
            else
            {
                cout << (int)aNumber << endl; // round down
            }
            break;
        }
    }
}