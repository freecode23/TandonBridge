#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int moreEvenCounter = 0;
    int num;
    cout << "Please enter a sequence of positive integers, each one in a separate line. End your sequence by typing -1:"<< endl;
    cin >> num;

    while(num != -1)
    {
        // initialize/ reset
        int evenCounter = 0;
        int oddCounter = 0;

        while(num !=0)
        {
            // move digit
            int lsb = num % 10;

            // check if this lsb is even
            if(lsb % 2 ==0)
            {
                evenCounter++;
            }
            else
            {
                oddCounter++;
            }
            // drop lsb
            num = num / 10;
        }
        // out of while loop compare odd and evencounter
        // if more even moreEvenCounter ++
        if(evenCounter > oddCounter)
        {
            moreEvenCounter++;
        }
        // get next number
        cin>> num;
    }
    cout << moreEvenCounter << endl;
}
