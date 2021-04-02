#include <iostream>
#include <string>
using namespace std;

int test(string text, int len, int index);
int totalVowels(string text, int len, int index);

int main()
{
    string text1 = "hello";
    int numOfVow = test(text1, text1.length(), 0);
    cout << numOfVow << endl;

}

int test(string text, int len, int index)
{
    return totalVowels(text, len, index);
}

int totalVowels(string text, int len, int index)
{

    int counter = 0;
    // Vowel
    string vowel = "AEIOU";

    // 1. base case
    // emptry string
    if (len == 0)
    {
        cout<<"true";
        return 0;
    }

    // way 2
    // conver first character to 0
    char char_caps = toupper(text[0]);
    // loop trhough vowel's list
    for(int i = 0; i < vowel.length(); i++)
    {
        if(char_caps == vowel[i])
        {
            counter ++;
        }
    }
    // ( remove first character, length is therefore -1, compare the first character)
    return counter + totalVowels(text.substr(1), text.length()-1, 0);
}
