#include <iostream>
#include <math>
using namespace std;

void printAsc(int start, int end)
{
    if (start == end)
    {
        cout << start << endl;
        return;
    }
    cout << start << endl;
    printAsc(start + 1, end);
}

void printAsc1(int start, int end)
{
    if (start == end)
    {
        cout << start << endl;
    }
    else
    {
        printAsc1(start, end - 1);
        cout << end << endl;
    }
}

void printAsdes(int start, int end)
{
    // base case
    if (start == end)
    {
        cout << start << endl;
    }

    // inductive
    // case 1: ascending
    if (start < end)
    {
        cout << start << endl;
        printAsdes(start + 1, end);
    }
    else if (start > end)
    {
        // case 2: descending
        cout << start << endl;
        printAsdes(end - 1, start);
    }
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

bool areAllEven(int arr[], int n)
{
    if (n == 1)
    {
        if (arr[0] % 2 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (arr[n - 1] % 2 == 0)
    {
        return areAllEven(arr, n - 1);
    }
    else
    {
        return false;
    }
}

// print ascending using recursion
int main()
{
    // printAsdes(2, 6);
    // cout << factorial(4) << endl;
    int n = 4;
    int arr[4] = {4, 6, 0, 2};
    cout << areAllEven(arr, n) << endl;
}

// Page 7
int func1(int n)
{
    int count;
    int i, j, k;
    count = 1;
    for (i = 1, j = 1; i <= n; i *= 2, j += 1)
    {
        for (k = 1; k <= j; k += 1)
        {
            count += 1;
        }
    }
    return count;
}

int func2(int n)
{
    int count;
    int i, j, k;

    count = 1;
    for (i = 1, j = 1; i <= n; i += sqrt(n), j += 1)
        for (k = 1; k <= j; k += 1)
        {
            count += 1;
        }
}

// page 8
int f1(int n)
{
    int count = 0;

    for (int i = n; i > 0; i /= 2)
        for (int j = 0; j < i; j++)
            count += 1;

    return count;
}

int f2(int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
        for (int j = i; j > 0; j--)
            count += 1;

    return count;
}

void f3(int n, int arr[])
{
    int i = 0, j = 0;

    for (; i < n; ++i)
        while (j < n && arr[i] < arr[j])
            j++;
}

void f4(int n)
{
    int i, x = 0;

    for (i = 1; i <= n; i++)
        if (i % 2 == 1)
            x++;
}