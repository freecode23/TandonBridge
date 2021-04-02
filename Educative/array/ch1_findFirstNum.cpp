#include<iostream>
using namespace std;

// Recursive function
int firstOccurrence(int array[], int size, int x, int currentIndex){
    // base case:
    if(currentIndex > size)
    {
        return 0;
    }

    // recursive case:
    if(array[currentIndex]== x)
    {
        return currentIndex;
    }
    else
    {
        return firstOccurrence(array, size,x, currentIndex+1);
    }
    
}

//Driver function

int main(){
    int array[] = {2,3,4,1,7,8,3};//define an array
    int x = 3;//define the number whose first occurence is to be found
    int size = 7;//define size of array
    cout<<"First Occurence of the number "<<x<<" is at index:";
    cout<<firstOccurrence(array,size,x,0);

    return 0;
}