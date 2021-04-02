/*
Name: Sherly Hartono
Hw 7
Question 2
Write a function:
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
The function takes as an input a positive integer num (≥ 2), and updates two output parameters
with the number of num's proper divisors and their sum.
For example, if this function is called with num=12, since 1, 2, 3, 4 and 6 are 12s proper divisors,
the function would update the output parameters with the numbers 5 and 16.
*/
#include <iostream>
#include <math.h>

using namespace std;
void analyzeDivisors(int num, int &outCountDivs, int &outSumDivs); 
bool isPerfect(int num);
bool isAmicable(int num1, int num2);
void printPerfectAndAmicableNumbers(int range);

int main()
{
    int num;
    int outCountDivs = 0;
    int outSumDivs = 0;
    // num = 284;
    cout<<"Enter a positive integer >= 2: ";
    cin>>num;
    printPerfectAndAmicableNumbers(num);
}
// pass by reference
// what will happen is:
// int &outCountDivs = count1
// outCountDivs now refers to the actual count1 address.
void analyzeDivisors(int num, int &outCountDivs, int &outSumDivs)
{
    // if num/div = k
    // 1. get div
    for (int i = 1; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            outCountDivs++;
            outSumDivs += i;
            // cout << i << " ";
        }
    }
    // 2. get k (excluding the number itself)
    for (int i = sqrt(num); i > 1; i--)
    {
        if (num % i == 0)
        {
            outCountDivs++;
            outSumDivs += (num / i);
            // cout << num / i << " ";
        }
    }
}

bool isPerfect(int num)
{
    int sumDivisor = 0;
    int outCountDivs = 0;
    analyzeDivisors(num, outCountDivs, sumDivisor);
    return (num == sumDivisor);
}

bool isAmicable(int num1, int num2)
{
    int outCountDivs = 0;
    int sumDivisor2 = 0;
    analyzeDivisors(num2, outCountDivs, sumDivisor2);

    if (num1 == sumDivisor2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printPerfectAndAmicableNumbers(int range)
{
    int outCountDivs;
    int outSumDivs;
    int amicable2;
    for (int num1 = 2; num1 <= range; num1++)
    {
        // reset Sum for every number
        outSumDivs = 0;
        outCountDivs = 0;
        // call analyzDivisors M times
        analyzeDivisors(num1, outCountDivs, outSumDivs);

        // check perfect
        if (num1 == outSumDivs)
        {
            cout << num1 << " is perfect" << endl;
        }
        else if ((outSumDivs <= range) && (num1 != outSumDivs))
        {
            // check amicable
            // call analyzDivisors another M times
            if (isAmicable(num1, outSumDivs))
            {
                // if this amicable2 has not already been checked. print both numbers
                if (num1 != amicable2)
                {
                    cout << num1 << " and " << outSumDivs << " are amicable pairs" << endl;
                }
                // update amicable larger number.
                amicable2 = outSumDivs;
            };
        }
    }
}