// https://www.chegg.com/homework-help/questions-and-answers/question-6-15-points-give-recursive-implementation-int-findfirstposition-int-arr-int-arrsi-q55703667

#include <iostream>
using namespace std;
int findFirstPosition(int arr[], int arrSize, int elem);
void printArray(int *arr, int arrSize);

int main()
{
    int arr[10] = {2, 15, 3, 8, 3, 10, 6, 23, 12, 32};

    // will return the index number of elem
    cout << findFirstPosition(arr, 10, 3) << endl;
    // should return 2

    cout << findFirstPosition(arr, 10, 7) << endl;
    // should return -1
}

int findFirstPosition(int arr[], int arrSize, int elem)
{
    // base case (once reached the end) or reached the first element
    if (arrSize == 0)
    {
        return -1;
    }
    else if(arr[0] == elem)
    {
        return 0;
    }

    // recursive save variable
    int i = findFirstPosition(arr + 1, arrSize - 1, elem);
    if(i == -1)
    {
        return -1;
    }
    else
    {
        return i + 1;
    }
}



