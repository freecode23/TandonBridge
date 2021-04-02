// print out a diamond with n maximum number of stars in a row:

#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Please enter the max number of star:" << endl;
    cin >> n;

    int initialSpace = n - 1;
    int stars = n - initialSpace;

    for (int i; i < 2 * n + 1; i++)
    {
        for (int j = 0; j <= initialSpace; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= stars; j++)
        {
            cout << "* ";
        }
        cout<< endl;
        if(i < n)
        {
            initialSpace--;
            stars++;
        }
        else
        {
            initialSpace++;
            stars--;
        }
    }
    // e.g 4
    //     *
    //   * * *
    //  * * * *
    //   * * *
    //    * *
    //     *
}