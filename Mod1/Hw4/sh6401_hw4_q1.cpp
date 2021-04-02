// Hw4 Question	1:	
// Author: Sherly Hartono
// Write two versions of program that reads	a positive integer n,
// and prints the first	n even numbers.	
// a) In the first,	use	a while loop.	
// b) In thesecond,	use	a for loop.	
// Each	section	should interact with the user exactly
// as it shows in the following	example:
// Please enter a positive integer: 3
// 2
// 4
// 6

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int nEvenNumbers;
    int counter = 1;
    // a) For loop
    cout << "Please enter a positive integer: ";
    cin >> nEvenNumbers;

    for(int i = 1; i <= nEvenNumbers; i++)
    {
        cout<< 2 * i <<endl;
    }

    // b) While loop
    while(nEvenNumbers !=0)
    {
        cout << counter * 2 <<endl;
        counter ++;
        nEvenNumbers--;
    }

}