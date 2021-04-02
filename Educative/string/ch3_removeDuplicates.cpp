#include <iostream>
#include <string>
using namespace std;


// remove duplicates right next to it. 
void remDuplicates(string &text, int index)
{
    // 1. base case if string is null( we reach the end of the strings)
    if (text[index] == '\0')
    {
        return;
    }

    // 2. recursive
    // if current text is the same as next
    if (text[index] == text[index + 1])
    {
        for (int position = index; position < text.length(); position++)
        {
            // replace current one with next one
            text[position] = text[position + 1];
        }

        remDuplicates(text, index);
    }

    remDuplicates(text, index + 1);
}

int main()
{
    string greeting = "Hello Woooorldd";
    remDuplicates(greeting, 0);
    cout << greeting << endl;
}


