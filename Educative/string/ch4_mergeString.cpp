#include <iostream>
#include <string>
using namespace std;

string alphabeticMerge(string one, string two)
{
    // 1. base case: 
    // a. one is empty
    if(one[0] == '\0') 
    {
        if(two[0] == '\0') // a.1 two is also empty
        {
            return two; // return one is ok too anyway both are empty
        }
        return two; // a.2 two is not empty
    } 
    // only two is empty
    else if(two[0] == '\0')
    {
        return one;
    }

    // comapre first char of each string
    //2. one's char is smaller 
    if(one[0] < two[0]) 
    {
        return one[0] + alphabeticMerge(one.substr(1),two); // merge
    }
    else
    {
        // two's char is smaller
        return two[0] + alphabeticMerge(one,two.substr(1));
    }
    

}

int main()
{

    string one = "adefz";
    string two = "bcfgy";
    string answer = alphabeticMerge(one, two);
    cout << answer << endl;
}
    // // 1. base case
    // // if first letter in first string is empty
    // if (one[0] == '\0')
    // {
    //     // if first letter in second string is empty
    //     if (two[0] == '\0')
    //     {
    //         // return first string (empty)
    //         return one;
    //     }
    //     // second string is not empty
    //     return two;
    // }
    // // 2. if first letter of Two is empty
    // else if (two[0] == '\0')
    //     return one;

    // // One is not empty:
    // // 3. if One's first char is greater than Two's first char
    // else if (one[0] > two[0])
    //     //two comes first, then the merge of One and Two'ssecond char
    //     return two[0] + alphabeticMerge(one, two.substr(1));

    // // One comes first
    // return one[0] + alphabeticMerge(one.substr(1), two);