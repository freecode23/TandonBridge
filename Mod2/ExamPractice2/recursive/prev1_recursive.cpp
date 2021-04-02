// https://www.chegg.com/homework-help/questions-and-answers/question-6-15-points-index-array-arr-called-fixed-point-arr-value-arr--example-array-arr-3-q69691523

#include <iostream>
using namespace std;

// will return the count of fixedPoint on smaller input
int findNumberOfFixedPoints(int arr[], int arrSize);
void printArray(int *arr, int arrSize);

int main()
{
    int arr[5] = {3, 1, 4, 7, 4};
    cout << findNumberOfFixedPoints(arr, 5);
}

int findNumberOfFixedPoints(int arr[], int arrSize)
{   
    // base case 
    if(arrSize == 0)
    {
        return 0;
    }

    // starts from back only
    if(arr[arrSize - 1] == (arrSize - 1))
    {
        return 1 + findNumberOfFixedPoints(arr, arrSize - 1);
    }
    else
    {
        return findNumberOfFixedPoints(arr, arrSize - 1);
    }

}
