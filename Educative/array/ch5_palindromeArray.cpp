#include <iostream>
using namespace std;

// Recursive function 
int palindrome(int arr[], int startIndex, int endIndex) 
{ 
    // base case
    // odd array: start == end
    // even array: start > end
    if ((startIndex == endIndex) || (startIndex >endIndex))
    {
        // palindrome
        return 1;
    }

    // if start and end match
    if(arr[startIndex] == arr[endIndex])
    {
        return palindrome(arr,startIndex+1, endIndex-1);
    }
    else
    {
        return 0;
    }
} 


//Driver function
// Driver code 
int main() 
{ 
    int array[] = { 1, 2, 2, 2, 1 };//declare an array
    int n = sizeof(array) / sizeof(array[0]);//calculate the size of the array
    int startIndex=0;//define the starting index
    int endIndex=n-1;//define the ending index
    if (palindrome(array, startIndex, endIndex) == 1) //call recursive function
        cout << "Array is a Palindrome"; 
    else
        cout << "Array is not Palindrome"; 
  
    return 0; 
} 