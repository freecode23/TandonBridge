#include <iostream>
using namespace std;

// will return the count of fixedPoint on smaller input
bool areAllEven(int arr[], int arrSize);
void printArray(int *arr, int arrSize);

int main()
{
    int arr[5] = {6, 2, 4, 8, 4};
    cout << areAllEven(arr, 5) <<endl;
}

bool areAllEven(int arr[], int arrSize)
{
    if (arrSize == 0)
    {
        return true;
    }

    if (arr[0] % 2 == 0)
    {
        return areAllEven(arr + 1, arrSize - 1);
    }
    else
    {
        return false;
    }
}