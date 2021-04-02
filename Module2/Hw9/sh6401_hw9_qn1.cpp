/*
Hw 9
Question 1
Name: Sherly Hartono
*/

#include <iostream>
#include <vector>
using namespace std;

void countOccurenceOfChar(string sentence, int *alphabetWordCount, int &wordCount)
{
    int sentenceIndex = 0;
    int alphabetIndex = 0;

    string word = "";
    char currentLetter = sentence[sentenceIndex];

    // 1. loop through the sentence line
    while (sentenceIndex <= sentence.length())
    {
        // 2. if current character is a delimiter
        if ((currentLetter == ',') || (currentLetter == '!') || (currentLetter == '.') || (currentLetter == ' '))
        {
            // 3. check if there's a word in our string
            if (word.length() > 0)
            {
                wordCount += 1;
            }
            // 4. reset our word
            word = "";
        }
        else // 5. current letter not delimiters
        {
            // 6. lower case first
            currentLetter = tolower(currentLetter);

            // 7. get alphabetIndex of this character a is index 0, b is index 1 etc.
            alphabetIndex = currentLetter - 'a';

            // 8. update alphabetWordCount
            alphabetWordCount[alphabetIndex] += 1;

            // 9. add this character to our word
            word += currentLetter;

            // if we reach the end of sentence after this word. add another word
            if(sentenceIndex == sentence.length() -1)
            {
                wordCount ++;
            }
        }
        // go to next character
        sentenceIndex++;

        // update current letter
        currentLetter = sentence[sentenceIndex];
    }
}

int main()
{
    string sentence;
    int wordCount = 0;
    // 1. get user input
    cout << "Please enter a line of text: " << endl;
    getline(cin, sentence);

    const int size = 26;
    // 2. count vector to store counts
    int alphabetWordCount[size] = {0};

    // 3. function that takes in sentence line, wordCount for 26 alphabets
    countOccurenceOfChar(sentence, alphabetWordCount, wordCount);

    // char c = (char) (1 + 'a');
    // int int1 = ('b' - 'a');
    // cout << c << endl;
    // cout << int1 << endl;

    cout << wordCount << "\t words" << endl;
    // 4. print alphabet
    for (int i = 0; i < size; i++)
    {
        if (alphabetWordCount[i] > 0)
        {
            cout << (char)(i + 'a') << "\t" << alphabetWordCount[i] << endl;
            // will convert 'a' to ascii number first add to i then convert to char
        }
    }
}
