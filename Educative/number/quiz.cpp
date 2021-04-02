#include <iostream>
using namespace std;

// Q1
int foo(int n)
{
    if (n == 12)
    {
     return n;
    }
    else 
    {
      return foo(n+1); // no additional stuff like n* foo(n+1) . so it will just return n
    }
}
 
int main()
{
   cout<<foo(3);
   return 0;
}


// Q2