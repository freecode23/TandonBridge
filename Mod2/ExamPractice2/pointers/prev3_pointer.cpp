// https://www.chegg.com/homework-help/questions-and-answers/4-5-question-5-30-points-median-finite-list-numbers-middle-number-numbers-listed-order-sma-q55704100

#include <iostream>

using namespace std;
void printArray(int *arr1, int arrSize);
double findMedian(int arr[], int arrSize);

int main()
{
    int arrOdd[7] = {3, 5, 3, 1, 7, 6};
    // if sorted: 1, 3, 3, 5, 4, 6, 7

    // freqArr  : 1, 0, 2, 0, 1, 1, 2
    // represent: 1, 2, 3, 4, 5, 6, 7
    // (freqIndex + 1)
    // we want to return this as median
    findMedian(arrOdd, 7);


    int arrEven[8] = {4, 1, 6, 2, 7, 3, 2, 8};
    // if sorted      : 1, 2, 2, 3, 4, 6, 7, 8

    // freqArr        : 1, 2, 1, 1, 0, 1, 1, 1
    // represent      : 1, 2, 3, 4, 5, 6, 7, 8
    findMedian( arrEven, 8);
}

double findMedian(int arr[], int arrSize)
{
    // 1. create frequency array
    int* freqArr = new int[arrSize];

    int freqIndex;
    // 2. fill in freqArr using arr
    for(int i = 0; i < arrSize; i++){
        freqIndex = arr[i] - 1;
        freqArr[freqIndex] += 1;
    }

    printArray(freqArr, arrSize);
    // 3. get sum until sum is greater than median Index
    // out of while loop means the index of
    // freqArray represents the median

    freqIndex = 0;
    // odd
    if(arrSize % 2 != 0)
    {
        // start from 0the element
        int xthElement = 0;

        // median is at Xth element
        int medianXthElement = arrSize / 2 + 1;
        while(xthElement < medianXthElement)
        {
            xthElement += freqArr[freqIndex++];
        }
        return freqIndex;
    }
    else // even
    {
        int medianXthElement1 = arrSize / 2;
        int medianXthElement2 = (arrSize / 2) + 1;
        double xthElement = 0;
        double xthElement2 = 0;

        // first median
        while(xthElement < medianXthElement1)
        {
            xthElement += freqArr[freqIndex++];
        }
        double median1 = freqIndex;

        // second median
        freqIndex = 0;
        while(xthElement2 < medianXthElement2)
        {
            xthElement2 += freqArr[freqIndex++];
        }
        double median2 = freqIndex;
        return ((median1 + median2) /2);
    }
}

void printArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}