/*
Name: Sherly Hartono
Hw 6 
Question 4
double eApprox(int n)
This function is given a positive integer n,
and returns an approximation of e, calculated by the sum of the first (n+1)
addends of the infinite sum above.
*/
#include <iostream>
using namespace std;

double eApprox(int n);

int main()
{
    cout.precision(30);

    for (int n = 1; n <= 15; n++)
    {

        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }
    return 0;
}


// There is only one loop here . That is no inner loop. so 
double eApprox(int n)
{
    double e = 1.00;
    double factorial = 1.00; 

    //find the e approximation by calculating
    for (int i = 1; i <= n; i++)
    {
        // 1st loop: (factorial = 1) * (i = 1)
        // 2nd loop: (factorial = 1)* (i = 2)
        // 3rd loop:(factorial = 2) * (i = 3)
        // nth loop
        factorial *= i; 
        e += (1 / factorial);
    }
    //return the approximation of e
    return e;
}

