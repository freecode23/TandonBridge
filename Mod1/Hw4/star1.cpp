#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter an integer n: ";
    cin >> n;

    int numberOfStars, numberOfSpaces,lineCount;
    for (lineCount = 1, numberOfStars = 1, numberOfSpaces = n - 1; // initialization
         lineCount <= n;                                               //condition
         lineCount++, numberOfStars++, numberOfSpaces--)               // increment
    {
        // space
        for (int spaceCount = 1; spaceCount <= numberOfSpaces; spaceCount++)
        {
            cout<< " ";
        }
        // stars
        for(int starCount = 1; starCount <= numberOfStars ;starCount++)
        {
            cout << "*";
        }

        // break line
        cout<< endl;
    }
}