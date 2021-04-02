#include <iostream>

using namespace std;
void printArray(int *arr1, int arrSize);
void oddKeepsEvensFlips(int arr[], int arrSize);

int main()
{
    int arr[6] = {5, 2, 11, 7, 6, 4};
    int arrSize = 6;
    oddKeepsEvensFlips(arr, arrSize);
    printArray(arr, 6);
    // 1. odd number keep orignal order
    // 2. even number will flip
    // [5,11,7,4,6,2]
}

void oddKeepsEvensFlips(int arr[], int arrSize)
{
    // 1. create temp Array to append our entries
    int *tempArr = new int[arrSize];

    // 2. keep track of odd and even index
    int oddIndex = 0;
    int evenIndex = arrSize-1;

    for (int i = 0; i < arrSize; i++)
    {
        // a) if odd
        if (arr[i] % 2 != 0)
        {
            // a1) if this is the first number to be added
            //    -> just add it
            if (oddIndex == 0)
            {
                tempArr[oddIndex] = arr[i];
            }
            else
            // a2) if its not the first number we need to compare
            {
                // a2.1) number that is appended is bigger
                if (tempArr[oddIndex - 1] > arr[i])
                {
                    // swap
                    // current will take the previous number (its bigger)
                    tempArr[oddIndex] = tempArr[oddIndex - 1];

                    // previous one will take the new number
                    tempArr[oddIndex - 1] = arr[i];
                }
                else// a2.1) number that is appended is smaller
                {
                    // just add
                    tempArr[oddIndex] = arr[i];
                }
            }
            oddIndex++;
        }
        else // if even
        {
            //add to the back
            tempArr[evenIndex--] = arr[i];
        }
    }
    
    // create copy
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = tempArr[i];
    }

    delete[] tempArr;
}

void printArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}