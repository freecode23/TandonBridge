#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void printRuler(int n)
{   
    // base case
    if(n==0)
    {
        return;
    }

    printRuler(n-1);
    
    // print first
    cout <<string(n,'-') <<endl;

    // decrement
    printRuler(n-1); // dont type return if you type return it wont implement the code below

    
}

int main()
{
    printRuler(3);
}