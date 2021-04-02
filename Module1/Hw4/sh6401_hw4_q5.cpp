/*
Hw 4 Question 5:
Author: Sherly Hartono
Write a program that asks the user to input a positive integer n,
and prints a textual image of an hourglass made of 2n lines with asterisks.

For example if n=4, the program should print: 
stars       |line  spaceLimits   starLimits
*******     |   1       0            2 * n - 1
 *****      |   2       1            2 * n - 3
  ***       |   3       2            2 * n - 5
   *        |   4       3            2 * n - 7
   *        |   1       n-1              1
  ***       |   2       n-2          ¡¡    3
 *****      |   3       n-3              5
*******     |   4       n-4              7

*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a positive integer n: ";

    cin >> n;

    // tophalf
    // line
    int starLimit, spaceLimit;
    for (int lineCount = 1, starLimit = 2 * n - 1, spaceLimit = 0; // initialize
         lineCount <= n; // condition
         lineCount++, starLimit -= 2, spaceLimit++) //increments
    {
        // space
        for (int spaceCount = 1; spaceCount <= spaceLimit; spaceCount++)
        {
            cout << " ";
        }

        // star
        for (int starCount = 1; starCount <= starLimit; starCount++)
        {
            cout << "*";
        }
        cout << endl;
    }

    //bottomhalf
    for (int lineCount = 1, starLimit = 1, spaceLimit = n - 1;
         lineCount <= n;
         lineCount++, spaceLimit--, starLimit += 2)
    {
        //space
        for (int spaceCount = 1; spaceCount <= spaceLimit; spaceCount++)
        {
            cout << " ";
        }

        //star
        for (int starCount = 1; starCount <= starLimit; starCount++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
