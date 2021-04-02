#include <iostream>

using namespace std;
int main()
{
    int num;
    int digit;
    int sum = 0;
    cout << "Enter a positive integer:"<<endl;
    cin >> num;

    // get copy of this number
    int numDisplay = num;

    while(num !=0)
    {
        // reset factorial
        int factorial = 1;

        // 1. get the first digit
        digit = num % 10;

        // 2. do stuff with this digit:
        // get the factorial of this digit
        for(int i =1; i <= digit; i++)
        {
            factorial *= i;
        }
        // add to sum factorial
        sum += factorial;

        // 3.remove this digit from the number
        num = num / 10;
    }

    // if sum factorial = num
    // this is a factorion
    if(sum == numDisplay)
    {
        cout << "factorion" <<endl;
    }
}