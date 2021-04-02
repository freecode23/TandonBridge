#include <string>
#include <iostream>
using namespace std;

void removeSpaces(string &text, int index, int len)
{
    //1. base case 1 empty string
    if (len == 0)
    {
        return;
    }
    //2. base case 2, we reach the end of the string
    if (index == len)
    {
        return;
    }
    // 3. if we are at empty space
    if (text[index] == ' ')
    {
        //4. do while loop:
        int i = index;
        // while we havent reach the end of the string,
        //shift everycharacter to replace the space
        while (i < len)
        {
            // replace current with next
            text[i] = text[i + 1];
            // go to next char until the end
            i++;
        }
        // remove space , with same index - at the start, but with length 1
        removeSpaces(text, index, len - 1);
    }

    // check next character
    removeSpaces(text, index + 1, len);
}

int main()
{
    string text = "  HO ME";
    cout << text << endl;
    removeSpaces(text, 0, text.length());
    cout << text << endl;
}
