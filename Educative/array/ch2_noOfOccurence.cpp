#include<iostream>
using namespace std;

// for counting:
// 1. base case: size ==0
// 2. recursive if( condition met)
//      counter ++
// recursive case: counter + recursivefunction(  )

// Recursive Function
int  NoOfOccurrence(int array[], int size, int num)
{
    int counter = 0;
    // base case:
    // counting use size
    if(size == 0)
    {
        return 0;
    }

    // recursive: still have numbers to recurse
    // start traversing from the end
    if(array[size]==num)
    {
        counter ++;
    }
    return counter + NoOfOccurrence(array,size-1,num); //use return for merging / accumulate things

}
// Driver Function
int main() {
  int array[7] = {2,3,4,1,7,8,3};//define an array
  int size=7;//define the size of array
  int num=3;// define the number whose frequency of occurrence is to be found
  cout<<"Number of occurrences of "<<num<<" : ";
  cout << NoOfOccurrence( array, size-1,num);//call recursive function
  return 0;
} 