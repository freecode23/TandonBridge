/*
Question 6 (15 points)
palindriome wihtout high and low
*/

#include <iostream>
using namespace std;
bool isPalindrome(int arr[], int arrSize);

int main()
{
    const int arrSize = 8;
    int arr[arrSize] = {1, 1, 2, 3, 4, 2, 1, 1};

    cout << isPalindrome(arr, arrSize) << endl;
}

bool isPalindrome(int arr[], int arrSize)
{
    // base case

    if ((arrSize == 0 && arrSize % 2 == 0) || (arrSize == 1 && arrSize % 2 != 0))
    {
        return true;
    }

    // recursive
    // if first == last
    if (arr[0] == arr[arrSize - 1])
    {
        // keep checking smaller input
        //           cut off first, cut off last by one more
        return isPalindrome(arr + 1, arrSize - 2);
    }
    else
    {
        return false;
    }
}