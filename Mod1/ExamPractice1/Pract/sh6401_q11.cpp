//
// Created by sherly hartono on 2/11/21.
// n = 4
//                  line  spaceLimit        starspaceLimit
// ...*              1        3 ( n - 1)          1
// ..* *             2        2                   2
// .* * *            3        1                   3
// * * * *           4        0                   4
//   if line >= n , swap counter spacelimit ++, startspaceLimit --
//  * * *            5        1                   3
//   * *             6        2                   2
//    *              7        3                   1

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    for(int lineCount = 1, spaceLimit = n - 1, starSpaceLimit = 1;
        lineCount <= 2 * n -1;
        lineCount++)
    {
        // 1. space
        for(int spaceCount = 1; spaceCount <= spaceLimit; spaceCount++)
        {
            cout << " ";
        }

        // 2. star space
        for(int starspaceCount = 1; starspaceCount <= starSpaceLimit; starspaceCount++)
        {
            cout << "* ";
        }
        // 3. reverse increment if line >= n
        if(lineCount >= n)
        {
            spaceLimit++;
            starSpaceLimit --;
        }
        else
        {
            spaceLimit--;
            starSpaceLimit ++;
        }
        cout << endl;
    }
}