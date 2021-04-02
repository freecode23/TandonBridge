#include <iostream>
#include <string>
using namespace std;

void func1(string str)
{
    int n;
    string subStr;
    n = str.length();

    for (int i = 1; i <= n; i += 1)
    {
        subStr = str.substr(0, i);
        cout << subStr << endl;
    }
}

void func1(string str)
{
    int n;
    string subStr;
    n = str.length();

    for (int i = 1; i <= n; i *= 2)
    {
        subStr = str.substr(0, i);
        cout << subStr << endl;
    }
}

// Qn1
//Give your answers in terms of asymptotic T(n) = Theta(n), or Theta(n^2)

void func1(int *arr, int n)
{
    int i;
    int *arr;

    for (i = n; i > 0; i--)
        reverseArray(arr, i);
}

void reverseArray(int *arr, int i)
{
    int left, right, temp;

    for (left = 0, right = i - 1; left <= right; left++, right--)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
}

// Qn2
//Give your answers in terms of asymptotic T(n) = Theta(n), or Theta(n^2)

int func2(int n)
{
    int i, j;
    int sum;

    arr = new int[n];
    // 1st
    for (i = 0; i < n; i += 1)
    {
        arr[i] = (i + 1);
    }
    sum = 0;

    //2nd
    for (i = 0; i < n; i++)
        for (j = 1; j <= arr[i]; j++)
            sum += (i + j);

    delete[] arr;
    return sum;
}

// Qn3
//Give your answers in terms of asymptotic T(n) = Theta(n), or Theta(n^2)

int func1(int n)
{
    int i, j;
    int count;

    arr = new int[n];
    for (i = 0; i < n; i += 1)
        arr[i] = (i % 2) + 1;

    count = 0;
    for (i = 0; i < n; i++)
        for (j = 1; j <= arr[i]; j++)
            count += 1;

    delete[] arr;
    return count;
}

// Qn 4:
//Give your answers in terms of asymptotic T(n) = Theta(n), or Theta(n^2)
int func2(int n)
{
    int i, j;
    int count;

    arr = new int[n];
    for (i = 0; i < n; i += 1)
        arr[i] = (n + i);

    count = 0;
    for (i = 0; i < n; i++)
        for (j = 1; j <= arr[i]; j++)
            count += 1;

    delete[] arr;
    return count;
}
//Aaron Slack
// TA Qn 1

void func1(int *arr, int n)
{
    for (i = n; i > 0; i--)
        reverseArray(arr, i);
}

void reverseArray(int *arr, int n)
{
    int left, right, temp;
    for (left = 0, right = n - 1; left <= right; left++ right--)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
}

Arithmetic Series
Sum = 2(n/2) + 2(n/2 -1) + 2(n/2 - 2) + ... + 2(2) + 2(1)
Theta(n^2)

//Aaron Slack
// TA Qn 2
void func2(int n)
{
    int i, j;
    int count;
    int* arr;

    arr = new int[n];
    arr[0] = 1;

    // 1st loop 
    for(i=1; i<n; i++)
        arr[i] = arr[i-1] + 2;
    
    count = 0;
    // 2nd loop
    for(i = 0); i < n; i++)
        for (j=1; j M= arr[i]; j++)
            count++;
}
Arithmetic Series
Sum = 1 + 3 + 5 + 7 + ... + (2n-1)
Theta(n^2)


// Piazza
// TA Qn 3
void algo1(string str)
{
    int n;
    string subStr;
    n = str.length();
    for(int i = 1; i <=n; i *=2)
    {
        subStr = str.substr(0,i);
        cout << subStr << endl;
    }
}

Sum = 1 + 2 + 4 + 8 + ... + n
or n + n/2 + n/4 + .... + 1
Total number of terms is n/2
The sum must be less than 2n
Theta(n)

// Piazza
// TA Qn 4
void algo2(int* arr, int n)
{
    int i, j;

    for(i = 1; i <= n ; i*=2)
        reverseArray(arr,i);
}

void reverseArray(int* arr, int n)
{
    int left, right, temp;

    for(left = 0; right = n-1; left <= right; left++; right--)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[left] = temp;
    }
}

Sum = 1 + 1 + 2 + 4 + ... + (n/2)
or    n/2 + n/4 + n/8 + ... + 2 + 1 + 1
must be less than n
Theta(n)