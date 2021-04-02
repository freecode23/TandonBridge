#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
void printOpositeTriangles(int n) This function is given a positive integer n,
and prints a textual image of a two opposite
right triangles (aligned to the left) with asterisks, each containing n lines.
For example, printOpositeTriangles(4), should print:

****
***
**
*
*
**
***
****
*/

void printOpositeTriangles(int n)
{   
    // base case
    if(n==0)
    {
        return;
    }

    // print first
    cout <<string(n,'*') <<endl;

    // decrement
    printOpositeTriangles(n-1); // dont type return if you type return it wont implement the code below

    cout <<string(n,'*') <<endl;
}

int main()
{
    printOpositeTriangles(5);
}

// print(5)
// 1st >> *****     print(5)     |    ^ 2nd cout (*****)                 just go back (nothing to do after return)
// 2nd >> ****      print(4)     |    | 2nd cout (****)
// 3rd >> ***       print(3)     |    | 2nd cout (***)
// 4th >> **        print(2)     |    | 2nd cout (**)
// 5th >> *         print(1)     |    | 2nd cout (*)
// 6th >> *         print(0)     return to print 1