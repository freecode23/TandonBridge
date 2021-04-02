#include <iostream>

using namespace std;
void makeXorArray(int *arr1, int n1, int *arr2, int n2, int **outXorArr, int *outN);
void printArray(int *arr1, int arrSize);

int main()
{
    const int n1 = 6;
    const int n2 = 4;
    int srtArr1[6] = {-1, 2, 3, 5, 7, 8};
    int srtArr2[4] = {2, 5, 6, 9};

    int *outArr;
    int outN = 0;

    makeXorArray(srtArr1, n1, srtArr2, n2, &outArr, &outN);

    printArray(outArr, outN);
    // should create arr1 = [1, 3, 6, 7, 8, 9]
    // Create an array, containing all the numbers that show in only one of the input arrays.
}

void makeXorArray(int *arr1, int n1, int *arr2, int n2, int **outXorArr, int *outN)
{
    // 1. create tempArray of n1 + n2. its maximum
    *outXorArr = new int[n1 + n2];
    int outIndex = 0;

    int index1 = 0;
    int index2 = 0;

    //2. loop through arr1 and arr2 while they
    // both haven't reached the end
    while ((index1 < n1) && (index2 < n2))
    {
        //if arr1 < arr2, add arr1 to tempArr
        if (arr1[index1] < arr2[index2])
        {
            (*outXorArr)[outIndex++] = arr1[index1++];
        }
        //if arr1 > arr2, add arr2 to (*outXorArr)
        else if (arr1[index1] > arr2[index2])
        {
            (*outXorArr)[outIndex++] = arr2[index2++];
        }
        //if arr1 == arr2, skip both                                                                                                                                                                      
        else if (arr1[index1] == arr2[index2])
        {
            index1++;
            index2++;
        }
    }
    // 4. exit while loop index1 and index2 is either at the next
    // number that occur once or they finish iteration
    while (index1 < n1)
    {
        (*outXorArr)[outIndex++] = arr1[index1++];
    }

    while (index2 < n2)
    {
        (*outXorArr)[outIndex++] = arr2[index2++];
    }
    //end of while loop means outIndex is now at last index+1
    // which we can use as the outN size
    *outN = outIndex;
}

void printArray(int *arr1, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr1[i] << " " << endl;
    }
}
