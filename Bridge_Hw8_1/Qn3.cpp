/*
Here, the function is given arr, an array of integers, and its logical size, arrSize.
The function should find the minimum value out of all the elements in positions: 0, 1, 2, …, arrSize-1.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int minInArray1(int arr[], int arrSize)
{
    // base case
    if (arrSize == 1)
    {
        // the only element
        return arr[0];
    }

    //recurisve condition
    // keep going down to the last element. 
    // min will take the value of the first element
    int min = minInArray1(arr, arrSize - 1);

    // min is from previous call
    // if min from prev. call is greater than the last element from this array
    if (min > arr[arrSize - 1])
    {
        min = arr[arrSize - 1];
    }
    return min; // will assign min to line 22
}

/*
int minInArray2(int arr[], int low, int high)
Here, the function is given arr, an array of integers,
and two additional indices: low and high (low ≤ high),
which indicate the range of indices that need to be considered.
The function should find the minimum value out of all the elements in positions:
low, low+1, …, high.

*/
int minInArray2(int arr[], int low, int high)
{
    // base case if low = high
    if (low == high)
    {
        return arr[low];
    }

    // recursive. keep cutting element to size 1
    // set this first element as min
    int min = minInArray2(arr, low, high - 1);

    // if min from previous call is greater than
    // [9] VS [9,-2]
    // if 9 > -2 
    if (min > arr[high - 1])
    {
        min = arr[high-1];
    }
    return min; // will assign min to line 52

}

int main()
{

    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};

    int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9); //should both be -9

    cout << res1 << " " << res2 << endl;

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4); //arr+2 is equivalent to &(arr[2])
    cout << res3 << " " << res4 << endl; //should both be 3
    return 0;
}