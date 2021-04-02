/*
Hw10
Qn 1
Give a recursive implement to the following functions:
a. void printTriangle(int n)
This function is given a positive integer n, and prints a textual image of a
right triangle (aligned to the left) made of n lines with asterisks.
For example, printTriangle(4), should print:
*       n = 4
**      n = 3
***     n = 2
****    n = 1

b. void printTriangle(int n)
This function is given a positive integer n, and prints a textual image of
a two opposite right triangles (aligned to the left) with asterisks, each containing n lines.
For example, printOpositeTriangles(4), should print:
****    n = 4
***     n = 3
**  
*
*
**
***
****

c. void printRuler(int n)
*/

#include <iostream>
#include <string>
using namespace std;
void printTriangle(int n);
void printTriangleOpp(int n);
void printRuler(int n);

int main()
{
    printTriangle(7);
    // printTriangleOpp(4);
    // printRuler(4);
}


//a.

void printTriangle(int n)
{
    // base case
    if (n == 1)
    {
        cout << "*" << endl;
        return;
    }

    // recursive case
    printTriangle(n - 1);

    // print using original arra
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
}

//b.
void printTriangleOpp(int n)
{
    // base case
    if (n == 1)
    {
        cout << "*" << endl;
        cout << "*" << endl;
        return;
    }

    // print original n
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;

    // recursive call
    printTriangleOpp(n - 1);

    // print original n
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;
}

//c.
void printRuler(int n)
{   
    // base case
    if(n==0)
    {
        return;
    }

    printRuler(n-1);
    
    // print dash n times
    for(int i = 0; i < n; i++)
    {
        cout << '-';
    }
    cout << endl;

    // decrement
    printRuler(n-1); 
}