/*
Hw 8
Question 6
Name: Sherly Hartono
Write a program that reads in a line of text and outputs the line with all the digits in all integer numbers replaced with 'x'.
>> Please enter a line of text:
My userID is john17 and my 4 digit pin is 1234 which is secret
>> My userID is john17 and my x digit pin is xxxx which is secret

Notes:
1. If a digits is part of a word, then the digit is not changed to an 'x'. For example, john17 is NOT changed to johnxx.
2. You may assume that the text entered by the user will contain only letters (upper case or lower case), digits and spaces.
3. Think how to break down your implementation to functions.
*/
#include <iostream>
#include <string>

using namespace std;
int getNumberOfWords(string sentence);
void insertWordsToArray(string sentence, string arrayOfWords[], int arrSize);
void printArray(string array[]);
bool isWordNumbers(string word);
void convertWordToX(string &wordAlias); // pass by reference wordAlias now refers to the actual word


void convertWordToX(string &wordAlias)
{
    for(int i = 0; i < wordAlias.length(); i ++)
    {
        wordAlias[i] = 'x';
    }
}

bool isWordNumbers(string word)
{
    for(int i = 0; i < word.length(); i ++)
    {
        // if any of the character is out of range
        if((word[i] < '0') || ( word[i] > '9'))
        {
            return false;
        }
    }
    return true;
}

void printArray(string array[], int arrSize)
{
    for(int i = 0; i < arrSize; i ++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertWordsToArray(string sentence, string arrayOfWords[], int arrSize)
{
    int sentenceIndex = 0;
    int spaceIndex = 0;
    int wordLength = 0;
    int arrayIndex = 0;
    string word = "";


    // while we havent gone through all the words and we can still find spaces
    // spaceIndex != std::string::npos --> this means spaceIndex is not non-existent
    while((sentenceIndex < sentence.length())&& (spaceIndex != std::string::npos))
    {
        // find next space from the start of sentence Index
        spaceIndex = sentence.find(" ", sentenceIndex);
        wordLength = spaceIndex - sentenceIndex;
        word = sentence.substr(sentenceIndex, wordLength);

        // add word to array
        arrayOfWords[arrayIndex] = word;

        // increment the start of the word, which is the index of space + 1
        sentenceIndex = spaceIndex + 1;
        
        arrayIndex ++;
    }
}


int getNumberOfWords(string sentence)
{
    // number of words is number of space + 1
    int numOfWords = 0;
    //1 for loop find number of space
    for(int i = 0; i< sentence.length(); i++)
    {
        if(sentence[i] == ' ')
        {
            numOfWords++;
        }
    }
    return numOfWords +1;
}

int main()
{
    // 1. get sentence
    string sentence;
    cout << "Please enter a line of text:\n";
    getline(cin, sentence);

    // 2. create array of all the words from the sentence
    const int ARR_SIZE = getNumberOfWords(sentence);
    string arrayOfWords[ARR_SIZE];

    insertWordsToArray(sentence, arrayOfWords, ARR_SIZE);

    // 3. convert array elements to xxx if they are digits
    for(int i = 0; i < ARR_SIZE; i++)
    {
        if(isWordNumbers(arrayOfWords[i]))
        {
            convertWordToX(arrayOfWords[i]);
        }
    }
    printArray(arrayOfWords,ARR_SIZE);
}