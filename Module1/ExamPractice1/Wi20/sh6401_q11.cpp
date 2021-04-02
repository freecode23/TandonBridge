/*Q11
 *
 * #######         lineCount   initSpaceLimit     dollar   midSpaceLimit    dollar     initSpaceLimit
 * #$   $#          1               0              1          3 (n-4)       1
 * # $ $ #          2               1              1          1             1
 * #  $  #          3               2              1          0             -
 * # $ $ #          4               1              1          1             1
 * #$   $#          5               0              1          3             1
 * #######
 */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Please enter an odd integer, greater or equal to 3: "<<endl;
    cin >> n;
    int median = (n-2)/2 + 1;
    cout << "median: " << median<< endl;
    // 1. cout 1st start hashline
    for(int i = 1; i <= n; i++)
    {
        cout << "#";
    }
    cout << endl;
    // 2. initialize lineCount and limits
    for(int lineCount = 1,initSpaceLimit = 0, midSpaceLimit = n-4;
        lineCount <= n-2; // lineCountLimit
        lineCount ++) // increment line count
    {
        // a) first hash
        cout << "#";

        // b) initial space
        for(int spaceCount = 0; spaceCount < initSpaceLimit; spaceCount++)
        {
            cout << " ";
        }

        // c) first dollar
        cout << "$";

        // d) mid space
        for(int midSpaceCount = 1; midSpaceCount <= midSpaceLimit; midSpaceCount++)
        {
            cout << " ";
        }

        // e) second dollar with condition
        if(lineCount != median)
        {
            cout << "$";
        }

        // f) initial space
        for(int spaceCount = 0; spaceCount < initSpaceLimit; spaceCount++)
        {
            cout << " ";
        }
        // g) last hash
        cout << "#";
        cout << endl; // go to next line

        // increment with condition
        if(lineCount < median)// top half
        {
            initSpaceLimit ++;
            midSpaceLimit -=2;

        }
        else // bottom half
        {
            initSpaceLimit --;
            midSpaceLimit +=2;
        }
    }
    // 10. cout final hashline
    for(int i = 1; i <= n; i++)
    {
        cout << "#";
    }
    cout <<endl;

}
