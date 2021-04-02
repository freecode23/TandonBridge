/*

Name: Sherly Hartono
Hw 6 
Question 4

void printDivisors(int num) This function is given a positive integer num,
and prints all of num’s divisors in an ascending order, separated by a space.

For Example, if we call printDivisors(100), the expected output is:
1 2 4 5 10 20 25 50 100

Implementation would run in Theta(sqrt(num))

*/


#include <iostream>
#include <math.h>
using namespace std;

void printDivisors(int num);

int main()
{
    int n;
    cout << "Please enter a positive integer >= 2: ";
    cin >> n;

    printDivisors(n);
}


void printDivisors(int num)
{
    for(int i = 1; i < sqrt(num); i++)
    {
        if (num % i ==0)
        {
            cout<< i << " ";
        }
    }

    for(int i = sqrt(num); i >= 1; i--)
    {
        if (num % i ==0)
        {
            cout<< num/i << " ";
        }
    }
    cout << endl;
}