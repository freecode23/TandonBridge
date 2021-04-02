/*
Hw 4 Question 4:
Author: Sherly Hartono
Write two versions of a program that reads a sequence of positive integers from 
the user, calculates their geometric mean, and print the geometric mean.

Your two versions should read the integer sequence in two ways:
a) First read the length of the sequence.

For example, an execution would look like:
Please enter the length of the sequence: 3 Please enter your sequence:
1
2
3
The geometric mean is: 1.8171

b) Keep reading the numbers until -1 is entered.

For example, an execution would look like:
Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:
1
2
3
-1
The geometric mean is: 1.8171
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float numSequenceA, lengthOfSeqA, productA = 1, geomMeanA;

    cout << "Please enter the length of the sequence: ";
    cin >> lengthOfSeqA;
    int counter = lengthOfSeqA;
    // a)
    cout << "Please enter your sequence: " << endl;
    while (counter != 0)
    {
        cin >> numSequenceA;
        productA *= numSequenceA; // multiply all the sequence
        counter --;
    }

    geomMeanA = pow(productA, 1 / lengthOfSeqA); // take the root
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    cout << "The geometric mean is: " << geomMeanA << endl;

    // b)
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line.";
    cout << "\nEnd your sequence by typing -1: " << endl;

    float numSequenceB, lengthOfSeqB = 0, productB =1, geomMeanB;

    cin >> numSequenceB;
    while(numSequenceB != -1)
    {
        productB *= numSequenceB;
        lengthOfSeqB ++;
        cin >> numSequenceB;
    }

    geomMeanB = pow(productB, 1 / lengthOfSeqB);
    cout << "The geometric mean is: " << geomMeanB << endl;
}