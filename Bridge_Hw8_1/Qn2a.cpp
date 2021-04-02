/*
Give a recursive implement to the following functions:
a. int sumOfSquares(int arr[], int arrSize)
This function is given arr, an array of integers, and its logical size, arrSize.
When called, it returns the sum of the squares of each of the values in arr.
For example, if arr is an array containing [2, -1, 3, 10],
calling sumOfSquares(arr, 4)
will return 114 (since, 2^2 + (-1)^2 + 3^2 + 10^2 = 114).
*/

# include <iostream>
# include <iomanip>
using namespace std;

int sumOfSquares(int arr[], int arrSize)
{
    // base case 
    if(arrSize==0)
    {
        return 0;
    }

    // return ( last element ^2)             + sumOfSquares( e element array)
    return (arr[arrSize-1] * arr[arrSize-1]) + sumOfSquares(arr, arrSize-1);
}
int main(){
    int arr[] = {2, -1, 3, 10};
    cout << sumOfSquares(arr, 4);

}