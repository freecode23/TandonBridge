#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void printTriangle(int n)
{
    // base case 
    if(n == 1)
    {
        cout<< "*\n";
        return;
    }

    // recursion first (decrement)
    printTriangle(n-1);

    //print
    cout<<string(n,'*') <<endl;
}

int main(){
    int n = 5;
    printTriangle(n);

}

// 1st >> print(5)     |    *****    ^
// 2nd >> print(4)     |    ****     |
// 3rd >> print(3)     |    ***      |
// 4th >> print(2)     |    **       | execute line 19
// 5th >> print(1)     V    *        | base case is first executed
                                       // called by  print 2