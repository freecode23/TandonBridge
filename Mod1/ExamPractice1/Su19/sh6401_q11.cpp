//
// Created by sherly hartono on 2/11/21.
// n = 5
//                line      star         InitSpaceLimit  star   midSpaceLimit            star
// *********               9 (2n -1)                                              (if midSpaceLimit !=0)
// .*.....*        1                          1           1          5 (2n-1)-4
// ..*...*         2                          2           1          3
// ...*.*          3                          3           1          1
// ....*           4                          4           1          0
//
//
#include <iostream>
#include <string>

using namespace std;
int main()
{

    char in = 's';
    int number = int(in);

    cout << number <<endl;
    cout << char(number) <<endl;
    // int n;
    // cout << "Enter n greater than or equals to 2:" <<endl;
    // cin >> n ;

    // // first line
    // for(int firstStarCount = 1; firstStarCount <= 2 * n - 1; firstStarCount++)
    // {
    //     cout<< "*";
    // }
    // cout << endl;
    // // iteration line
    // for(int lineCount = 1, initSpaceLimit = 1, midSpaceLimit = (2*n-1)-4;
    // lineCount < n;
    // lineCount++, initSpaceLimit++, midSpaceLimit -=2)
    // {
    //     // 1. space
    //     for(int initSpaceCount = 1; initSpaceCount <= initSpaceLimit; initSpaceCount++)
    //     {
    //         cout<< " ";
    //     }

    //     //2. star
    //     cout << "*";

    //     //3. midspace
    //     for(int midSpaceCount = 1; midSpaceCount <= midSpaceLimit; midSpaceCount++)
    //     {
    //         cout<< " ";
    //     }

    //     //4. final star
    //     if(midSpaceLimit > 0)
    //     {
    //         cout << "*";
    //     }
    //     //5. next line
    //     cout << endl;
    
}