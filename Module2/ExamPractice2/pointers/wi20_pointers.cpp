/*
 * This function takes two base addresses of arrays of integers: srtArr1 and srtArr2,
 * and their respective logical sizes: n1 and n2. The elements in each array come in
 * a sorted (strictly ascending) order.
 * When called, it should create an array, containing all the
 * numbers that are in srtArr1 and not in srtArr2.
 */

#include <iostream>

using namespace std;
void printArray(int *arr1, int arrSize);
void makeDifferenceArray(int *arr1, int n1, int *arr2, int n2, int *&outArr, int &outN);

int main()
{
    const int n1 = 10;
    const int n2 = 4;
    int arr1[n1] = {1, 2, 3, 5, 7, 8, 10, 12 ,13, 14};
    int arr2[n2] = {2, 5, 6, 9};
    int *outArr;
    int outN = 0;
    makeDifferenceArray(arr1, n1, arr2, n2, outArr, outN);
    // should create array [ 1, 3, 5, 7, 8]
    printArray(outArr, outN);
}


void makeDifferenceArray(int *arr1, int n1, int *arr2, int n2, int *&outArr, int &outN)
{
    // 1. outArr have size n1 + n2
    outN = n1 + n2;
    outArr = new int[outN];

    // we will cut this size later by using count variable
    int outIndex = 0; // this will be our outArrSize
    int index1 = 0;
    int index2 = 0;

    // 2. insert element by comparing value of arr1 and arr2
    // ( loop through arr1 and arr2)
    while(index1 < n1 && index2 < n2){
        // a) if arr1[index1] < arr2[index2] -> insert arr1[index1]
        //    increment index1 and outIndex
        //    count++
        if(arr1[index1] < arr2[index2]){
            outArr[outIndex++] = arr1[index1++];
        }
        // b) if arr1[index1] == arr2[index2] -> skip
        //    increment both index
        else if(arr1[index1] == arr2[index2]){
            index1++;
            index2++;
        }
        // c) if arr1[index1] > arr2[index2] -> don't insert to outArr
        //    increment index2
        else if(arr1[index1] > arr2[index2]){
            index2++;
        }
    }

    //3. Out of while loop means arr1 might still have
    // remaining numbers that has not been inserted
    // do another loop through arr1
    while (index1 < n1)
    {
        outArr[outIndex++] = arr1[index1++];
    }

    //4. resize array outN = count
    outN = outIndex;
}


void printArray(int *arr1, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr1[i] << " " << endl;
    }
}
