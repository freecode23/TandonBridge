#include <iostream>

using namespace std;

int euclidGCD(int dividend, int divisor);
int gcd(int num1, int num2);

int main()
{
    int num1;
    int num2;
    cout<< "input the bigger number: " ;
    cin>> num1;
    cout<< "input the smaller number: ";
    cin>> num2;

    int GCD = euclidGCD(num1,num2);
    cout<< "GCD is " << GCD <<endl;
}

int euclidGCD(int dividend, int divisor)
{
    int remainder = dividend % divisor;

    // base case
    if(remainder == 0)
    {
        return divisor;
    }
    else
    {
        // divisor becomes the dividend
                                 // remainder becomes the divisor
        return euclidGCD(divisor,remainder);
    }
}

// GCD 1002 and 999
// 1002 mod 999 = 3 ( 999*1 remainder 3)                            --> 1st number divided by 2ndnumber
// 999 mod 3 = 0 ( divisor 3 is GCD as it gives remainder 0)        --> 2nd number divided by this remainder is 0. of course then this R is GCD.
// when the remainder is 0, then divisor must be able to divide both num1 and num2


// Educativ solution
int gcd(int num1, int num2)
{
  // base case
  if (num1==num2)
  {
    return num1;
  }
  //recursive case
  if(num1 > num2)
  {
    gcd(num1-num2, num2);
  }
  
  else if(num2 > num1)
  {
    gcd(num1, num2-num1);
  }
}

// int main() 
// {
//   int x=42;
//   int y=56;
//   // computing gcd and storing it in result
//   int result= gcd(42,56);
//   // printing result
//   cout<<"Greatest Common Divisor of "<<x<<" and "<<y<<" is "<<result; 
//   return 0;
// }