#include <iostream>
using namespace std;

//Recursive function

// same as []array. make sure its pointer to this array because we woant to change outside the scope
//replaceNegativeValues(int array[], int size, int currentIndex)
void replaceNegativeValues(int *array, int size, int currentIndex)
{
    //base case
    if(currentIndex==size)
    {
        return ;
    }

    //recursive
    if(array[currentIndex] < 0) // if its a negatie integer
    {
        //replace with 0
        array[currentIndex] = 0;
    }
    return replaceNegativeValues(array, size, currentIndex+1);
}

//Driver Function
int main()
{
    int array[7] = {2, -3, 4, -1, -7, 8, 3}; //define an array
    int size = 7;                            //define the size of array
    cout << "Replace negative values with 0:\n";
    replaceNegativeValues(array, size, 0); //call the recursive function
    for (int i = 0; i < 7; i++)            //print the array
        cout << array[i] << ' ';
    return 0;
}