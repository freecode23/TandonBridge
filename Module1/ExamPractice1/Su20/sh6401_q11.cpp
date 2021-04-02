/*
 * Please enter a positive integer: 5
 * odd integer
 *          line          start       charLimit    end
 * XOX0X     1 (odd)       XO         n-1 /2      X
 * OXOXO     2 (even)      OX                     O
 * XOXOX     3             XO                     X
 * OXOXO     4             OX
 * XOXOX     5             XO
 *Please enter a positive integer: 8
 * even integer
 *                line      start       charLimit    end
 * XOXOXOXO     1 (odd)       XO         n/2
 * OXOXOXOX     2 (even)      OX         n/2
 * XOXOXOXO
 * OXOXOXOX
 * XOXOXOXO
 * OXOXOXOX
 * XOXOXOXO
 * OXOXOXOX
 *
 *
 */



#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    //    cout << setf(ios::fixed);
    //    cout << setf(ios::showpoint);
    cout<< "Please enter a positive integer: ";
    cin >> n;

    int charLimit;
    string startOddLine = "XO";
    string startEvenLine = "OX";
    string endOddLine;
    string endEvenLine;
    if(n%2 == 0)//even
    {
        charLimit = n/2;
        endOddLine = "";
        endEvenLine = "";
    }else
    {
        charLimit = (n-1)/2;
        endOddLine = "X";
        endEvenLine = "O";
    }

    //print
    // for each line
    for(int lineCount = 1; lineCount<= n; lineCount++)
    {
        // 1. print repeated character
        for(int charCount =1; charCount <= charLimit ; charCount++)
        {
            if(lineCount % 2 == 0)   // 1. even line
            {
                cout << startEvenLine;
            }
            else // 2. odd line
            {
                cout << startOddLine;
            }
        }

        // 2. print end character
        if(lineCount % 2 == 0)   // 1. even line
        {
            cout << endEvenLine;
        }
        else // 2. odd line
        {
            cout << endOddLine;
        }
        cout<< endl;
    }
}