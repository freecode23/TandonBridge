/*
Hw 8
Question 5
Name: Sherly Hartono
Write a program that reads a person’s name in the following format:
first name, then middle name or initial, and then last name.

The program then outputs the name in the following format: 
Last_Name, First_Name Middle_Initial.

For example, the input
Mary Average User
should produce the output:
User, Mary A.

The input Mary A. User should also produce the output: 
User, Mary A. 

Note that your program should work the same and
place a period after the middle initial even if the input did
not contain a period.

Hint: You may want to use three string variables rather than one 
large string variable for the input.
You may find it easier to not use getline.
*/

#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int const ARRAY_SIZE = 3;

void printName(string arr[], int size);
void printArray(string arr[], int size);
void capitalizeStringInArray(string arr[], int size);

void printName(string arr[], int size)
{
    // Last name                First name
    cout << arr[2] << ", " << arr[0] << " "<<arr[1][0] << "." <<endl;
}

void printArray(string arr[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << index << " ";
        cout << arr[index];
    }
}

void capitalizeStringInArray(string arr[], int size)
{
    for (int index = 0; index < size; index++)
    {
        arr[index][0] = toupper(arr[index][0]);
    }
}

int main()
{
    // 1. prompt user
    cout << "Enter name: " << endl;
    string nameArr[ARRAY_SIZE];


    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        cin >> nameArr[index];
    }
    // 2. capitalize 
    capitalizeStringInArray(nameArr, ARRAY_SIZE);

    // 3. print name
    printName(nameArr, ARRAY_SIZE);

}