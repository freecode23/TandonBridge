/*
Please enter an odd integer, greater or equal to 3:
7
                       lineCount-1              n-4       
#######     lineCount initSpace     dollar    midSpace     dolllar  initSpace
#$   $#       1        0              1         3             1          0
# $ $ #       2        1              1         1             1
#  $  #       3        2              1         0             0
# $ $ #       4        1            
#$   $#       5        0
#######

Please enter an odd integer, greater or equal to 3:
5
#####
#$ $#         
# $ #
#$ $#
#####
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please enter an odd integer: " << endl;
    cin >> n;

    //1. 1st line hash
    for (int hashCount = 1; hashCount <= n; hashCount++)
    {
        cout << "#";
    }
    cout << endl;
    //2. for each line

    for (int lineCount = 1, initSpaceLimit = 0, midSpaceLimit = n - 4;
         lineCount <= n - 2;
         lineCount++)
    {
        // a) 1st hash
        cout << "#";
        // b) 1st space
        for (int initSpaceCount = 0; initSpaceCount < initSpaceLimit; initSpaceCount++)
        {
            cout << " ";
        }
        // c) dollarstart
        cout << "$";
        // d) midSpace11
        for (int midSpaceCount = 1; midSpaceCount <= midSpaceLimit; midSpaceCount++)
        {
            cout << " ";
        }

        if (midSpaceLimit > 0)
        {
            // e) dollarend
            cout << "$";
        }
        // f) 2nd space
        for (int initSpaceCount = 0; initSpaceCount < initSpaceLimit; initSpaceCount++)
        {
            cout << " ";
        }

        // d) last hash
        cout << "#";
        cout<< " midSPaceLimit "<<midSpaceLimit;
        cout << endl;
        
        int medianOfLineCount = int((n-2)/2);

        // switch increment/decrement after median lineCount
        if(lineCount <= medianOfLineCount) 
        {
            midSpaceLimit -=2; // topHalf
            initSpaceLimit ++;
        }
        else //bottomHalf
        {
            midSpaceLimit +=2;
            initSpaceLimit --;

        }
    }

    //3. last line hash
    for (int hashCount = 1; hashCount <= n; hashCount++)
    {
        cout << "#";
    }
    cout<<endl;
}
