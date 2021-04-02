/*
Hw 9
Question 4
Name: Sherly Hartono
Implement the function:
void oddsKeepEvensFlip(int arr[], int arrSize)
This function gets an array of integers arr and its logical size arrSize.

When called, it should reorder the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).
For example, if arr = [5, 2, 11, 7, 6, 4], after calling oddsKeepEvensFlip(arr, 6),
arr will be: [5, 11, 7, 4, 6, 2]
*/

#include <iostream>
using namespace std;

void printArr(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
    // 1. create new temporary array in heap to store the sorted array
    int arrTemp[arrSize];

    int arrTempIndexFront = 0;
    int arrTempIndexBack = arrSize - 1;
    // 2. loop through the old array
    for (int i = 0; i < arrSize; i++)
    {
        // if odd add to the front of arrTemp
        if (arr[i] % 2 == 1)
        {
            arrTemp[arrTempIndexFront] = arr[i];
            arrTempIndexFront++;
        }
        else
        {
            // if even add to the back of arrTemp
            arrTemp[arrTempIndexBack] = arr[i];
            arrTempIndexBack--;
        }
    }

    //3. loop through new array and replace the old array
    int index = 0;

    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = arrTemp[i];
    }    
}

int main()
{
    const int arrSize = 6;
    int arr[arrSize] = {0, 1, -2, 0, 2, -3};

    oddsKeepEvensFlip(arr, arrSize);
    printArr(arr, arrSize);
}