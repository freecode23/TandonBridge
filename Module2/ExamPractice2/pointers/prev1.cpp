#include <iostream>

using namespace std;
void printArray(int *arr1, int arrSize);
void findMissing(int *arr, int n, int **outArr, int *outN);

int main()
{
    int arr[6] = {3, 1, 3, 0, 6, 4}; // our index
    int *outArr;
    int outSize = 0;
    findMissing(arr, 6, &outArr, &outSize);
    printArray(outArr, outSize);
    //new outArr should be [2,5]
}

void findMissing(int *arr, int n, int **outArr, int *outN)
{
    // 1. create frequency array of Size n
    int freqArrSize = n + 1;
    int *freqArr = new int[freqArrSize];

    cout << n <<endl;

    // 2. loop through arr, and increment frequency on frqArr[ arr[0]].
    for(int i = 0; i < n ; i++)
        freqArr[arr[i]] += 1;

    printArray(freqArr, freqArrSize);

    // 3. loop through freq array
    // if index is 0, increment outN (size of our outArr)

    for(int i = 0; i < freqArrSize; i++)
        if(freqArr[i] == 0)
            (*outN) += 1;

    // 4. append the index at which freqArr is missing to our outArr

    *outArr = new int[(*outN)];
    int outArrIndex = 0;

    for(int i = 0; i < freqArrSize; i++)
        if(freqArr[i] == 0)
            (*outArr)[outArrIndex++] = i;


    delete[] freqArr;
}

void printArray(int *arr1, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr1[i] << ", ";
    }
    cout << endl;
}
