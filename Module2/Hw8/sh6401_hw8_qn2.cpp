/*
Name: Sherly Hartono
Qn 2
A palindrome is a word, which reads the same backward or forward.
For example, noon, civic, radar, level, rotor,
kayak, reviver, racecar, redder, madam, and refer are all palindromes.

a. Implement a function:
bool isPalindrome(string str) This function is given a string str containing a word,
and returns true if and only if str is a palindrome.

b. Write a program that reads a word from the user and announces to the user if it is a palindrome or not.
Your program should interact with the user exactly as it shows in the following example:
Please enter a word: level
level is a palindrome
*/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
// a. 
bool isPalindrome(string str)
{
    int frontIndex = 0;
    int backIndex = str.size()-1;

    // 1. iterate through character in the string
    while(frontIndex <= backIndex)
    {
        // 2. If front character is the same as back character AND the index havent moved past each other
        if((str[frontIndex]== str[backIndex])&& (frontIndex <= backIndex))
        {
            // 3. keep checking
            frontIndex++;
            backIndex--;
        }
        // 4. If front and back character does not match AND the indexes haven't collide
        else if((str[frontIndex]!= str[backIndex])&& (frontIndex < backIndex))
        {
            // 5.
            // cannot be palindrome
            return false;
        }
    }
    // the index have moved past each other 
    return true;
}


// b.
int main()
{
    string word1;
    cout << "Please enter a word: ";
    cin >> word1;
    if(isPalindrome(word1))
    {
        cout << word1 << " is a palindrome" << endl;
    }
    else
    {
        cout << word1 << " is not a palindrome" << endl;
    }
}