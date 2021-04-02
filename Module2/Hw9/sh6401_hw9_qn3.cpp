/*
Hw 9
Question 3
Name: Sherly Hartono
In this question, you will write four versions of a function getPosNums
that gets an array of integers arr, and its logical size.
When called it creates a new array containing only the positive numbers from arr.

For example, if arr=[3, -1, -3, 0, 6, 4],
the functions should create an array containing the following 3 elements: [3, 6, 4],
*/

#include <iostream>
using namespace std;
void printArr(int *arr, int arrSize);

// 1. not passing any pointer or reference. we are returning the address/ pointer variable.
// that the pointer outside can then take
int *getPosNums1(int *arr, int arrSize, int &outPosArrSize);
int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr);

// 2. array is created inside the function. the pointer / reference from outside is updated inside the function
void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize);
void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr); 



void printArr(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
a)
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
returns the base address of the array (containing the positive numbers),
and updates the output parameter outPosArrSize with the array’s logical size.
*/
int *getPosNums1(int *arr, int arrSize, int &outPosArrSize)
{
    //1. get size of for the new array
    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet positivenumber
        if (arr[index] > 0)
        {
            // increment positive slot
            outPosArrSize++;
        }
    }
    // 2. create new dynamic array
    int *arr1 = new int[outPosArrSize];
    int newIndex = 0;

    // 3. add positive numbers to this new array
    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet positivenumber
        if (arr[index] > 0)
        {
            // assign this number to our new arr1
            arr1[newIndex] = arr[index];
            newIndex++;
        }
    }
    return arr1;
}

/*
b) change integer to integer pointer
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
returns the base address of the array (containing the positive numbers)
and uses the pointer outPosArrSizePtr to update the array’s logical size.
*/
int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr)
{
    // make size = 0 first
    *outPosArrSizePtr = 0;

    //1. get size of for the new array
    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet positive number
        if (arr[index] > 0)
        {
            // increment size
            (*outPosArrSizePtr)++;
        }
    }
    // 2. create new dynamic array
    int *arr1 = new int[(*outPosArrSizePtr)];
    int newIndex = 0;

    // 3. add positive numbers to this new array
    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet positivenumber
        if (arr[index] > 0)
        {
            // assign this number to our new arr1
            arr1[newIndex] = arr[index];
            newIndex++;
        }
    }
    return arr1;
}

/*
c) change integer to integer pointer
created a reference to array outside the function
inside the function this reference will be an alias to a new array
*/
void getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize)
{
    // make size = 0 first
    outPosArrSize = 0;

    //1. get size of for the new array
    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet positivenumber
        if (arr[index] > 0)
        {
            // increment positive slot
            outPosArrSize++;
        }
    }
    // 2. create new dynamic array
    // outPosArr(arr3) is an alias to a pointer that stores address of integer array
    outPosArr = new int[outPosArrSize];
    int newIndex = 0;

    // 3. add positive numbers to this new array
    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet positivenumber
        if (arr[index] > 0)
        {
            // assign this number to our new arr1
            outPosArr[newIndex] = arr[index];
            newIndex++;
        }
    }
}

void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr)
{
    // make size = 0 first
    *outPosArrSizePtr = 0;

    //1. get size of for the new array
    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet positive number
        if (arr[index] > 0)
        {
            // increment size
            (*outPosArrSizePtr)++;
        }
    }
    // 2. create new dynamic array
    // *outPosArr (arr4) is a pointer stores address of integer array

    *outPosArrPtr = new int[(*outPosArrSizePtr)];
    int newIndex = 0;

    // 3. add positive numbers to this new array
    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet positive number
        if (arr[index] > 0)
        {
            // assign this number to our new arr4
            (*outPosArrPtr)[newIndex] = arr[index];

            newIndex++;
        }
    }
}

int main()
{
    const int arrSize = 6;
    int arr[arrSize] = {7, -1, -3, 0, 6, 200};
    int outPosArrSize = 0;

    //a)
    cout << "a: " << endl;
    int *arr1 = getPosNums1(arr, arrSize, outPosArrSize);
    printArr(arr1, outPosArrSize);
    delete[] arr1;
    arr1 = nullptr;

    //b) int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr)
    cout << "b: " << endl;
    int *arr2 = getPosNums2(arr, arrSize, &outPosArrSize);
    printArr(arr2, outPosArrSize);
    cout << outPosArrSize << endl;
    delete[] arr2;
    arr2 = nullptr;

    //c)
    int *arr3;
    cout << "c: " << endl;
    getPosNums3(arr, arrSize, arr3, outPosArrSize);
    printArr(arr3, outPosArrSize);
    delete[] arr3;
    arr3 = nullptr;

    //d) void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
    int *arr4;
    cout << "d: " << endl;
    getPosNums4(arr, arrSize, &arr4, &outPosArrSize);
    printArr(arr4, outPosArrSize);
    delete[] arr4;
    arr4 = nullptr;
}
