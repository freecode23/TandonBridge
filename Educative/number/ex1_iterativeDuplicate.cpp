#include <iostream>
#include <string>

using namespace std;

// Iteration code that goes through the string , print each word and delete duplicated


int main()
{
    string name = "Hello Worldd";

    // for character that we get, check if there is duplicate going throughout the whole thing
    for (int i = 0; i < name.length(); i++)
    {
        char character = name[i];
        cout<< "loop1: "<<character<<endl;
        // 2nd loop
        for(int j =i+1; j< name.length(); j++)
        {
            if(character == name[j])
            {
                // remove this character
                name = name.substr(0,j) + name.substr(j+1, name.length()-1);
            }
        }
    }
}

/**
   pow(2,5) => 
2* pow(2,4)  2               *     = 32
2* pow(2,3)  2           *   = 16
2* pow(2,2)  2       *   = 8
2* pow(2,1)  2    *  = 4
2* pow(2,0)  2 *  = 2
   pow(2,0)      1

*/