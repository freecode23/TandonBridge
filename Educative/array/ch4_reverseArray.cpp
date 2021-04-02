#include <iostream>
using namespace std;

//Recursive function for Reversing array
void reverseArray(int arr[], int startIndex, int endIndex) 
{
    // base case 
    // for odd, start = end. 
    // for even, startIndex>endIndex
    if((startIndex == endIndex)|| (startIndex>endIndex))
    {
        return;
    }
    // swap
    int temp;
    temp = arr[startIndex];
    arr[startIndex] = arr[endIndex];
    arr[endIndex] = temp;

    return reverseArray(arr, startIndex+1,endIndex-1);


} 
//Driver function
int main()
{
   int array[5]={1,2,3,4,5};//define the array
   int size=5;//define the size of array
   reverseArray(array,0,size-1); //call the recursive function
   cout<<"Reversed Array:"; 
   for (int i=0;i<5;i++)
     cout<<array[i];//print the array
   return 0; 
}