/*
Question 6 (15 points)

A sequence is called a 2-dup sequence if its first two elements are equal to one another,
the following 2 elements are equal to one another, etc.
For example the sequence: 3, 3, 14, 14, 2, 2 is a 2-dup sequence. But, 3, 3, 5, 7 is not.

Give a recursive implementation for:
bool is2dupSequence(int seq[], int seqSize)
The function is given seq, an array containing a sequence of integers,
and its logical size, seqSize. When called, it should return true,
if seq represents a 2dup sequence, or false otherwise.
*/

#include <iostream>
using namespace std;
bool is2dupSequence(int arr[], int arrSize);

int main()
{
    const int arrSize = 6;
    int arr[6] = {3, 3, 14, 14, 2, 7};

    cout << is2dupSequence(arr, arrSize) << endl;
}

bool is2dupSequence(int arr[], int arrSize)
{
    // base case
    if (arrSize == 0)
    {
        return true;
    }
    // recursive
    // check if first two is duplicate
    if (arr[0] == arr[1])
    {
        // keep checking the rest
        return is2dupSequence(arr + 2, arrSize - 2);
    }
    else
    {
        return false;
    }
}