/*
Name: Sherly Hartono
Hw 6 
Question 1
the first 10 numbers in Fibonacci sequence are: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

1. Write a function int fib(int n) that returns the n-th element of the Fibonacci sequence.

2. Write a program that prompts the user to enter a positive integer num,
and then prints the num’s elements in the Fibonacci sequence.

Your program should interact with the user exactly as it shows in the following example:
Please enter a positive integer: 7
13

*/

#include <iostream>
using namespace std;

int fib(int num);

int main()
{
    int num;
    cout << "Please enter a positive integer: ";
    cin >> num;

    cout << fib(num)<<endl;
}


//1. fib function
int fib(int num)
{

    int f1 = 1;
    int f2 = 1;
    int fn = 0;
    if (num <= 2)
    {
        return f1;
    }
    else
    {
        while (num > 2)
        {
            fn = f1 + f2;
            f1 = f2; // 1
            f2 = fn; // 2
            // cout << fn <<endl;
            num--;
        }
        return fn;
    }
}