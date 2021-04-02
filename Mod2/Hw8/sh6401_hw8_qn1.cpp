/*
Name: Sherly Hartono
Hw 8 Qn 1
1.
Implement the function: int minInArray(int arr[], int arrSize)
This function is given arr, an array of integers, and its logical size,
arrSize. When called, it returns the minimum value in arr.
*/
#include <iostream>
using namespace std;
const int SIZE = 20;
void printMinIndex(int arr[], int minNum, int arrSize)
{
    cout << "The minimum value is " << minNum<< ", and it is located in the following indices:";
    for(int i = 0; i <= arrSize; i++)
    {
        if(arr[i] == minNum)
            cout << i << " ";
    }
    cout<<endl;

}

int minInArray(int arr[], int arrSize)
{
    int i;
    int min = arr[i];
    for(i = 0; i < arrSize-1; i++)
    {  
        if(arr[i+1] <= min )
        {
            min = arr[i+1];
            // cout << "min: "<< min <<endl;
        }
    }
    return min;
}

int main()
{
    int arr1[SIZE];

    cout << "Please enter 20 integers seperated by a space:\n";
    for(int i = 0; i < SIZE; i++)
    {    
        cin >> arr1[i];
    }
    int minNum = minInArray(arr1, SIZE);
    printMinIndex(arr1, minNum, SIZE);
}