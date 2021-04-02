#include <iostream>

using namespace std;
void printArray(int *arr1, int arrSize);
void intToBitsArr(int num, int **outBitsArr, int &outBitsArrSize);

int main()
{
    int arrSize = 0;
    int num = 38;
    // {1, 0, 0, 1, 1, 0};
    int *outArr;

    // cout << (char) (2 + 'a') <<endl;
    intToBitsArr(num, &outArr, arrSize);
    printArray(outArr, arrSize);
}

void intToBitsArr(int num, int **outBitsArr, int &outBitsArrSize)
{
    // 1. get arrSize while looping thorough division
    int originalNum = num;
    int remainder = 0; // remainder is the bit
    while(num != 0)
    {
        outBitsArrSize++;
        num = num/2;
    } 

    // 2. initialize bitsArr of size outbitsArr
    *outBitsArr = new int[outBitsArrSize];

    // 3. loop thorough number again, and append the
    // remainder from the back to this array
    num = originalNum;
    int index = outBitsArrSize - 1;
    while(num != 0)
    {
        remainder = num % 2;
        // append
        (*outBitsArr)[index--] = remainder;
        num = num/2;
    }
}

void printArray(int *arr1, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}
