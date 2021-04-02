/*
 *
 * Please enter a positive integer: 5
 * 5                                       initialize
 *                      line     initSpaceLimit     starLimit
 *     *****             1            4 (n-1)          5 n
 *    *******            2            3  --            7 += 2
 *   *********           3            2                9
 *  ***********          4            1               11
 * *************         5            0               13
 *
 */



#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;

    //for each line
    for(int lineCount = 1, initSpaceLimit = n-1, starLimit = n;
    lineCount <= n;
    lineCount++, initSpaceLimit --, starLimit +=2)
    {
        // 1. initSpace
        for(int initSpaceCount = 1; initSpaceCount <= initSpaceLimit; initSpaceCount++)
        {
            cout << " ";
        }
        // 2. star
        for(int starCount = 1; starCount<= starLimit; starCount++)
        {
            cout << "*";
        }
        //3. end line
        cout << endl;
    }
}