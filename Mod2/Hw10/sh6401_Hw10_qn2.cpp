/*
Name: Sherly
Hw 10
Qn 2

All elements in arr are in the range {0, 1, 2, … , n}.
Note that since the array contains n numbers taken from a range of size n+1,
there must be at least one number that is missing
(could be more than one number missing, if there are duplicate values in arr).
if arr=[3, 1, 3, 0, 6, 4], after calling findMissing(arr, 6, resArrSize)
the function should create and return an array that contains [2, 5]
 and update the value in resArrSize to be 2.
*/

#include <iostream>
#include <string>

using namespace std;

int *findMissing(int arr[], int n, int &resArrSize)
{
    // 1. create an array that will record the frequency of occurence of 0 to n from input arr
    int *frequency = new int[n + 1];

    // 2. loop through input arr
    for (int i = 0; i < n; i++)
    {
        // 3. set the number inside arr1 as index for our frquency
        int indexToIncrement = arr[i];

        // 4. update the frequency array
        frequency[indexToIncrement] += 1;
    }

    // 5. Get missing array size
    for (int i = 0; i < n + 1; i++)
    {
        // frequency 0 means number is missing
        if (frequency[i] == 0)
        {
            resArrSize++;
        }
    }

    // 6. initialize missing array
    int *missingArr = new int[resArrSize];

    // 7. add missing numbers to missing array
    int missingArrIndex = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (frequency[i] == 0)
        {
            missingArr[missingArrIndex] = i;
            missingArrIndex++;
        }
    }
    delete[] frequency;
    return missingArr;
}

int main()
{
    const int arrSize = 6;
    int arr1[arrSize] = {3, 1, 3, 0, 6, 4};
    int missingArrSize = 0;

    int *missingArr = findMissing(arr1, arrSize, missingArrSize);

    cout << "missingArr now contains: \n";
    for (int i = 0; i < missingArrSize; i++)
    {
        cout << missingArr[i] << " ";
    }

    cout << "\nIts size is: " << missingArrSize << endl;
    delete[] missingArr;
    missingArr = nullptr;
}