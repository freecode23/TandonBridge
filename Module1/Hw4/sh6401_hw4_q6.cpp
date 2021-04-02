/*
Hw 4 Question 6:
Author: Sherly Hartono
Write a program that asks the user to input a positive integer n,
and print all of the numbers from 1 to n that have more even digits than odd digits.

For example, if n=30, the program should print:
2 4 6 8 20 22 24 26 28

*/

#include <iostream>

using namespace std;

int main()
{
    int n, lsb, evenCounter, oddCounter;

    cout << "Enter a positive integer n: ";
    cin >> n;

    // for each integer before n
    for (int i = 2; i <= n; i++)
    {
        int num = i;

        evenCounter = 0, oddCounter = 0; //reset to 0 for each integer
        while (num > 0) // no more digit to interpret
        {
            int lsb = num % 10; // mod 10 will give you LSB

            if ((lsb % 2 == 0) && (lsb != 0)) // even means its divisible by 2, and its not 0
            {
                evenCounter++;
            }
            else if (lsb % 2 != 0)
            {
                oddCounter++;
            }
            num = num / 10; // div 10 will take out LSB from your number
        }

        if (evenCounter > oddCounter)
        {
            cout << i << endl;
        }
    }
}
