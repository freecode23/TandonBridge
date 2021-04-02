/*
Hw 9
Question 2
Name: Sherly Hartono
Two strings are anagrams if the letters can be rearranged to form each other.
For example, “Eleven plus two” is an anagram of “Twelve plus one”.
Each string contains one ‘v’, three ‘e’s, two ‘l’s, etc.

Write a program that determines if two strings are anagrams.
The program should not be case sensitive and should disregard any punctuation or spaces. 

Notes:
1. Think how to break down your implementation to functions.
2. Pay attention to the running time of your program.
If each input string contains 𝑛 characters, an efficient implementation
would run in a linear time (that is Θ ( 𝑛 ) ).
*/

#include <iostream>
#include <string>
using namespace std;
const int ALPHABET_SIZE = 26;

void countOccurenceOfChar(string sentence, int *alphabetArray);
bool isAnnagram(string string1, string string2);
bool isArraySame(int *alphabetArray1, int *alphabetArray2);

bool isArraySame(int *alphabetArray1, int *alphabetArray2)
{
    for (int index1 = 0; index1 < ALPHABET_SIZE; index1++)
    {
        if (alphabetArray1[index1] != alphabetArray2[index1])
        {

            return false;
        }
    }
    return true;
}

void countOccurenceOfChar(string sentence, int *alphabetArray)
{
    int sentenceIndex = 0;
    int alphabetIndex = 0;

    char currentLetter = sentence[sentenceIndex];

    // 1. loop through the sentence line
    while (sentenceIndex <= sentence.length())
    {
        // 6. lower case first
        currentLetter = tolower(currentLetter);
        if ((currentLetter >= 'a') || (currentLetter <= 'z')) // 5. current letter not delimiters
        {
            // 7. get alphabetIndex of this character a is index 0, b is index 1 etc.
            alphabetIndex = currentLetter - 'a';

            // 8. update alphabetArray
            alphabetArray[alphabetIndex] += 1;
        }
        // go to next character
        sentenceIndex++;

        // update current letter
        currentLetter = sentence[sentenceIndex];
    }
}

bool isAnnagram(string string1, string string2)
{
    //1. get alphabet array of string1
    int alphabetArray1[ALPHABET_SIZE] = {0};
    countOccurenceOfChar(string1, alphabetArray1);

    //2. get alphabet array of string2
    int alphabetArray2[ALPHABET_SIZE] = {0};
    countOccurenceOfChar(string2, alphabetArray2);

    //3. compare the two arrays
    return isArraySame(alphabetArray1, alphabetArray2);
}

int main()
{
    string string1, string2;

    cout << "Please enter the first string: \n";
    getline(cin,string1);

    cout << "Please enter the second string: \n";
     getline(cin,string2);

    // string string1 = "Mr. Mojo risin";
    // string string2 = "Jim Morrisonk";
    if (isAnnagram(string1, string2))
    {
        cout << "The two strings are anagram" << endl;
    }
    else
    {
        cout << "The two strings are NOT anagram" << endl;
    }
}