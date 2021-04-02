#include <iostream>
#include <string.h>

using namespace std;

int *mysteryAlg(int n, int p, int *arr1);

int *mysteryAlg(int n, int p, int *arr1)
{
    //arr1 points to what arrNum is pointing to.

    int icounter = 0;
    int jcounter = 0;
    int swapcounter = 0;
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        cout << "outer while loop. i is: " << i << " j is: " << j << endl;

        //1.
        // i moves to the right as long as they havent collide
        // and the value is less than p
        while ((i < j) && (arr1[i] < p))
        {
            icounter++;
            // cout << "inner i loop. i is: " << i << endl;
            // cout << "arr1[i]=" << arr1[i] << endl;
            i++;
            cout << "i++: " << icounter << endl;
        }
        //2.
        // out of while loop value in index i is greater than p.
        // j moves to the left as long as the value is greater than p
        // cout << "           <<<out of i loop, i = " << i << " <<<<" << endl;
        while ((i < j) && (arr1[j] >= p))
        {
            jcounter++;
            // cout << "inner j loop. j is: " << j << endl;
            // cout << "arr1[j]=" << arr1[j] << endl;
            j--;
            cout << "j--: " << jcounter << endl;
        }
        // out of both while loop means
        // out of while loop value in index j is smaller than p. or i and j collide
        // cout << "           <<<out of j loop, j = " << j << " <<<<" << endl;
        // cout << " i is: " << i << ", j is: " << j << endl;

        //3. swap
        if (i < j)
        {
            swapcounter++;
            cout << "swap++: " << swapcounter << endl;
            // cout << "swap i and j" << endl;
            int temp;
            temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
        }
        cout << "END OF FIRST IT" << endl;
        cout << endl;

        // cout << "ARR after first IT: " << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr1[i] << " ";
        // }
        // cout << endl;
    }
    return arr1;
}

int main()
{
    int arrNum[7] = {0, -2, -10, -110,  -120, -140, -150};
    int n = 7;

    cout << "array before: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arrNum[i] << " ";
    }
    cout << endl;
    cout << endl;

    mysteryAlg(n, 0,arrNum);
    cout << endl;
    cout << "array after: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arrNum[i] << " ";
    }
}