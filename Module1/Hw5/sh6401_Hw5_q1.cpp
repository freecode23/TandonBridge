/* Homework 5
 * Question 1
 * Author: Sherly Hartono
 * Prompt user for a positive integer n
 * then create a table of n X n multiplication table
 * Line
 * 1      1   2  3  4  5          (1 * 1,2,3,4,5
 * 2      2   4  6  8  10         (2 * 1,2,3,4,5
 * 3      3   6  9  12 15
 * 4      4
 * 5      5
 */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a positive integer n: ";
    cin >>n;

    //  for each lineMultiple 1 - n
    //  print    lineMultiple * 1 to n
    for(int lineCount = 1; lineCount <= n; lineCount++)
    {
        // number
        for(int numberCount = 1; numberCount <=n; numberCount++)
        {
            cout << lineCount * numberCount << "\t";
        }
        cout<< endl;
    }


}
