#include <iostream>

using namespace std;

//Recursive function to sort the array
void SortArray(int arr[],int startIndex, int size)
{
    //Write code here

}

void printSortArray(int *numbers, int size)
{
    //call SortArray
    SortArray(numbers, 0, size);
    for (int i = 0; i < size; i++)
        cout << numbers[i] << ' ';

}

int main()
{
    int numArr[] = {3, 2, 9, 1, 8};
    int size = 5;
    printSortArray(numArr, size);
    return 0;
}

