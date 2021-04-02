/*
Name: Sherly Hartono
Qn 3
A palindrome is a word, which reads the same backward or forward.
For example, noon, civic, radar, level, rotor,
kayak, reviver, racecar, redder, madam, and refer are all palindromes.

a. 

b. Write a program that reads a word from the user and announces to the user if it is a palindrome or not.
Your program should interact with the user exactly as it shows in the following example:
Please enter a word: level
level is a palindrome
*/

#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int &arrSize);
void splitParity(int arr[], int arrSize);

void printArray(int arr[], int arrSize)
{
    int i;
    for (i = 0; i < arrSize; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

/*
a)
Takes arr, an array of integers, and its size, arrSize.
When called, it reorders the elements of the array to appear in a reverse order.
For example, if arr is an array containing [1, 2, 3, 4], after calling reverseArray,
arr will look like: [4, 3, 2, 1].
*/
void reverseArray(int arr[], int arrSize)
{
    // initializing pointer *arr to store the address of pointer *arr_argument
    // int *arr = *arr_argument
    int frontIndex = 0;
    int backIndex = arrSize - 1;
    int temp;

    while (frontIndex <= backIndex)
    {
        // swap
        temp = arr[frontIndex];
        arr[frontIndex] = arr[backIndex];
        arr[backIndex] = temp;

        // increment and decrement index
        frontIndex++;
        backIndex--;
    }
}
/*
b) removeOdd
Takes arr, an array of integers, and its size, arrSize.
When called, the function alters arr so that the only numbers in
it at the end are the even ones, which should remain in their original
relative order.

Additionally, the function updates arrSize so it contains the
new logical size of the array after removing the odd numbers
(note that arrSize is a parameter used both for input and output).

For example, if arr is an array containing [1, 2, 3, 4], after calling removeOdd,
arr will look like: [2, 4], and the parameter arrSize will update to 2.
Notice the values in arr[2] and arr[3] are discarded.
*/
void removeOdd(int arr[], int &arrSize)
{
    // keep track of slot number to insert even element
    int evenSlot = 0;

    for (int index = 0; index < arrSize; ++index)
    {
        // if we meet even number
        if (arr[index] % 2 == 0)
        {
            // insert at this
            arr[evenSlot] = arr[index];

            // increment even slot
            evenSlot++;
        }
    }
    arrSize = evenSlot;
}

/*
c)
Takes arr, an array of integers, and its size, arrSize
When called, the function changes the order of numbers in arr so that
all the odd numbers will appear first, and all the even numbers will appear last.
Note that the inner order of the odd numbers and the inner order of
the even numbers don’t matter.
For example, if arr is an array containing [1, 2, 3, 4],
after calling splitParity, arr could look like: [3, 1, 2, 4].
*/
void splitParity(int arr[], int arrSize)
{
    int backIndex = arrSize - 1;
    int temp = 0;
    int currentIndex = 0;

    while (currentIndex <= backIndex)
    {
        // 1. if current is even move to the back
        if (arr[currentIndex] % 2 == 0)
        {
            // 2. while number at back index is even, keep moving
            while ((arr[backIndex] % 2 == 0) & (currentIndex < backIndex))
            {
                backIndex--;
            }
            // 3. out of while loop means element at backIndex is odd
            // 4. swap if the indices haven't collide
            if (currentIndex < backIndex)
            {
                temp = arr[backIndex];
                arr[backIndex] = arr[currentIndex];
                arr[currentIndex] = temp;
            }
        }
        currentIndex++;
    }
}

int main()
{
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    // 1. reverse
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    // 2. remove
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    // 3. split
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    return 0;
}