/*
0 3 80 6 57 10
The object of the game is to move from the first column to the last column with the lowest total cost.

The number in each column represents the cost to enter that column.
You always start the game in the first column and have two types of moves.
You can either move to the adjacent column or jump over the adjacent column to land two columns over.
The cost of a game is the sum of the costs of the visited columns.

In the board shown above, there are several ways to get to the end.
Starting in the first column, our cost so far is 0. We could jump to 80, then jump to 57,
and then move to 10 for a total cost of 80 + 57 + 10 = 147. However, a cheaper path would be
to move to 3, jump to 6, then jump to 10, for a total cost of 3 + 6 + 10 = 19.

Write a recursive function that solves this problem and returns the lowest
cost of a game board represented and passed as an array.

Note: your function shouldn’t output the actual sequence of jumps,
only the lowest cost of this sequence.

*/

#include <iostream>
#include <iomanip>
using namespace std;

int jump(int arr[], int startIndex, int size)
{
    //base case 
    // if we reach the end
    if(startIndex == size-1)
    {
        // not jumping anymore
        return 0;
    }
    // if adjacent > next next
    if(arr[startIndex+1]> arr[startIndex+2])
    {
        cout<< "jump to next next, value:" << arr[startIndex+2]<<endl;
        // jump to next next and make a jump from there
        return arr[startIndex+2]+ jump(arr, startIndex+2, size);
    }
    // else jumpt to adjacent
    cout<< "jump to adjacent, value:" << arr[startIndex+1]<<endl;
    return arr[startIndex+1]+ jump(arr, startIndex+1, size);
}

int main()
{
    int arr[]={0 ,3, 80, 6, 57, 10};
    cout << jump(arr, 0, 6);
}