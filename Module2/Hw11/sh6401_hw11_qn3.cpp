/*
Hw11
Qn3
Write two recursive versions of the function minInArray.
The function will be given a sequence of elements and should
return the minimum value in that sequence.
The two versions differ from one another in the technique we use
to pass the sequence to the function.
*/

#include <iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main()
{
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};

    int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<" "<<res2<<endl;

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout << res3 << " " << res4 << endl;

    return 0;
}

int minInArray1(int arr[], int arrSize)
{
    // base case
    if(arrSize == 1)
    {
        return arr[0];
    }
    // go deep
    int min = minInArray1(arr + 1, arrSize - 1);

    //compare first and last (2nd)
    if(arr[0] < min)
    {
        min = arr[0];
    }
    return min;
}

int minInArray2(int arr[], int low, int high)
{
    // base case
    if(low == high)
    {
        return arr[0];
    }

    // get minimum of the smaller input
    int min = minInArray2(arr, low, high - 1 );

    // compare min to last array that is not included in input
    if(min > arr[high])
    {
        min = arr[high];
    }
    return min; 
}
