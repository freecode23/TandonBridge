/*
Hw10
Qn 2
Give a recursive implement to the following functions:

a. int sumOfSquares(int arr[], int arrSize)
This function is given arr, an array of integers, and its logical size, arrSize.
When called, it returns the sum of the squares of each of the values in arr.
For example, if arr is an array containing [2, -1, 3, 10],
calling sumOfSquares(arr, 4)
will return 114 (since, 2^2 + (-1)^2 + 3^2 + 10^2 = 114).

b. bool isSorted(int arr[], int arrSize)
This function is given arr, an array of integers, and
its logical size, arrSize. When called, it should return true if the elements
in arr are sorted in an ascending order, or false if they are not.
*/

#include <iostream>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
int sum(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main()
{
    const int arrSize = 4;
    int arr[arrSize] = {1, 2, 3, 0}; // just sum = 13
    // cout << sumOfSquares(arr, arrSize) << endl;
    cout << isSorted(arr, arrSize) << endl;
}

int sumOfSquares(int arr[], int arrSize)
{
    // base case
    if (arrSize == 1)
    {
        return (arr[0] * arr[0]);
    }
    // start from back                          remove back
    // return (arr[arrSize-1] * (arr[arrSize-1])) + sumOfSquares(arr, arrSize - 1);
    // start from front           remove front
    return (arr[0] * arr[0]) + sumOfSquares(arr + 1, arrSize - 1);
}

bool isSorted(int arr[], int arrSize)
{
    // 1. base case
    if((arrSize == 0) || (arrSize ==1))
    {
        // 2. we have checked everything and they are sorted
        return true;
    }

    // 3. compare first element and next element
    if(arr[0] < arr[1])
    {
        // 4. keep comparing next
        return isSorted(arr+1, arrSize-1);
    }
    else
    {
        return false;
    }
}

