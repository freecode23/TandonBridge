/*  
Name: Sherly Hartono
Hw 6 
Question 2
n spaces          line  space
...... ....$         1    4
...... ...$$$        2    3
...... ..$$$$$       3    2
...... .$$$$$$$      4    1
...... $$$$$$$$$     5    0

.... ..+             1    2
.... .+++            2    1
.... +++++           3    0

1. It prints an n-line triangle, filled with symbol characters, shifted m spaces from the left margin.
2. It prints a sequence of n triangles of increasing sizes (the smallest triangle is a 2-line triangle),
which form the shape of a pine tree. The triangles are filled with the symbol character.

   +
  +++
   +
  +++
 +++++
   +
  +++
 +++++
+++++++
*/

#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main()
{
    int n;
    char symbol;

    cout << "Enter the number of triangle n and symbol. \nExample '3 +'  : ";
    cin >> n >> symbol;

    printPineTree(n, symbol);
}

void printPineTree(int n, char symbol)
{
    for(int treeCount = 1, spaceLimit = n-1, lineLimit = 2;
     treeCount <= n ;
      spaceLimit--, treeCount++, lineLimit++)
    {
        printShiftedTriangle(lineLimit,spaceLimit,symbol);
    }
}

void printShiftedTriangle(int n, int m, char symbol)
{
    // initialize
    for(int lineCount = 1, spaceLimit = m + (n-1) , symbolLimit = 1; lineCount <= n; lineCount++, spaceLimit--, symbolLimit+=2 )
    {
        // space
        for(int spaceCount = 1; spaceCount <= spaceLimit; spaceCount ++)
        {
            cout << " ";
        }

        // symbol
        for(int symbolCount = 1; symbolCount <= symbolLimit; symbolCount ++)
        {
            cout << symbol;
        }
        
    cout <<endl;
    }
}
