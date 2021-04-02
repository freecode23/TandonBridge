#include <iostream>
#include <string>
using namespace std;

int test(string text);
int isPalindrome(string text, int front, int back);

int main()
{
    string text1 = "MADAM";
    string text2 = "ALI";
    string text3 = "monom";
    cout<<test(text1 )<<endl;
    cout<<test(text2)<<endl;
    cout<<test(text3)<<endl;
}


int isPalindrome(string text, int front, int back)
{  
    // base case cond:
    // 1. if finish front == back (index)
    if (front == back)
    {
        return 1;
    }

    // recursive case:
    // 1. if front char == back char
    if(toupper(text[front]) == toupper(text[back]))
    {
        // 2. keep checking 
        return isPalindrome(text, front+1, back-1);
    }
    else
    {
        return 0;
    }
}

// Function to test your code
// Don't change any code below this
int test(string text) {
  
  int answer= isPalindrome(text,0,text.length()-1);
  if (answer)
  {cout<< "Yes" <<endl;}
  else
  {cout<< "No" <<endl;}
  return answer;
}