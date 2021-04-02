/*
Name: Sherly
Hw 10
Qn 1
For example, if sentence=”You can do it”,
after calling createWordsArray(sentence, outWordsArrSize),
the function should create and return an array that contains
[”You” , ”can” , ”do” , ”it”],
and update the value in outWordsArrSize to be 4.

1. You may want to use some of the string methods, such as find, substr, etc.
2. Your function should run in linear time.
That is, if sentence contains n characters, your function should run in 𝜃 (n)
*/

#include <iostream>
#include <string>

using namespace std;

int getNumberOfWords(string sentence);
void printArray(string *sentencePtr);
string *createWordsArray(string sentence, int &outWordsArrSize);

void printArray(string *sentencePtr, int arrSize)
{   
    cout << "Print array: " <<endl;
    for(int i = 0 ; i < arrSize; i++)
    {
        cout << sentencePtr[i] << " ";
    }
    cout << endl;
}

string *createWordsArray(string sentence, int &outWordsArrSize)
{
    // 1. get array size
    outWordsArrSize = getNumberOfWords(sentence);

    // 2. create empty string array of size of sentence in heap
    string *wordArr = new string[outWordsArrSize];
    int sentenceIndex = 0;
    string word = "";

    // 3. loop through the array 3 times
    for(int i = 0; i < outWordsArrSize; i++)
    {
        // 4. get wordLength at the start of each array index
        int pos = sentence.find(" ", sentenceIndex);
        int wordLength = pos - sentenceIndex ;

        // 5. get word
        word = sentence.substr(sentenceIndex, wordLength);

        // 6. insert to array
        wordArr[i] = word;

        // 7. update sentence index
        sentenceIndex = pos + 1;
    }
    return wordArr;
}

int getNumberOfWords(string sentence)
{
    int outWordsArrSize = 0;

    // 1. check for empty string
    if (sentence.length() == 0)
    {
        return 0;
    }
    else //2. not empty string
    {
        // loop through each character
        for (int i = 0; i < sentence.length(); i++)
        {
            // 3. if find a space increment outWordsArrSize
            if (sentence[i] == ' ')
            {
                outWordsArrSize += 1;
            }
        }
        // 4. add 1 more to outWordsArrSize
        return outWordsArrSize + 1;
    }
}

int main()
{
    string sentence;
    string *sentencePtr;
    int outWordsArrSize = 0;

    cout << "Enter a sentence: " << endl;
    getline(cin, sentence);

    sentencePtr = createWordsArray(sentence, outWordsArrSize);

    printArray(sentencePtr, outWordsArrSize);
    cout << "outWordsArrSize is now: " << outWordsArrSize <<endl ;

    delete[] sentencePtr;
    sentencePtr = nullptr;
}