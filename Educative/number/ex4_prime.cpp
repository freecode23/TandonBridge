#include <iostream>
#include <math.h>
using namespace std;

int isPrime(int n, int i)
{
    // we divide n by prime number from 2 to upper_limit 'u'. 
    // if we reach 'u' and the remainder is not 0, it means this is prime
    int current_prime = 2;
    int upper_limit = floor(sqrt(n)); 

    // while we havent reach the upper limit => still possible prime 1
    // and remainder is not zero => still possible prime 2
    while((current_prime < upper_limit) && (n % current_prime > 0))
    {
        // keep moving up, divide by the next prime
        current_prime ++;
    }

    // either prime has reach upper limit 
    if(current_prime == upper_limit)
    {
        return 1; // its prime
    }
    else // it hasnt reach upper limit which means remainder is 0
    {
        return 0; //not prime
    }
}

// function to test your code
// do not change this
int main(int num)
{
    int prime = isPrime(num, num / 2);
    cout << "prime or not: " << prime;
    return prime;
}
