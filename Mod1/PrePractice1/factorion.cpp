#include <iostream>

using namespace std;

int factorial(int n);

int main()
{

    int num;
    int digit;
    int digitCount = 0;
    int sum = 0;

    cout << "Please enter a positive integer:";
    cin >> num;

    while (num >= 10)
    {
        // extract the last digit
        digit = num % 10; // will return the remainder of number divided by 10
        cout << "num " << num << endl;
        cout << "digit" << digit << endl;

        // if digit is 0 just +=1
        if (digit != 0)
        {
            sum += factorial(digit);
        }
        else
        {
            sum+=1;
        }
        
        num /= 10;
    }
    sum += factorial(num);

    cout << "sum: " << sum << endl;
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}