/*
b. bool isSorted(int arr[], int arrSize) This function is given arr, an array of integers,
and its logical size, arrSize. When called, it should return true if the
elements in arr are sorted in an ascending order, or false if they are not.
*/

#include <iostream>
#include <iomanip>
using namespace std;

bool isSorted(int arr[], int arrSize)
{
    // base case
    // no prev element
    if (arrSize == 1)
    {
        return 1;
    }

    // recursive
    // lastElement > prevElement
    if (arr[arrSize - 1] > arr[arrSize - 2])
    {
        return isSorted(arr, arrSize - 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int arr1[] = {2, -1, 3, 10};
    cout << isSorted(arr1, 4);

    int arr2[] = {-1, 1, 3, 10};
    cout << isSorted(arr2, 4);

    int arr3[] = {-1, 1, 3, 10, 20,100};
    cout << isSorted(arr3, 6);
}