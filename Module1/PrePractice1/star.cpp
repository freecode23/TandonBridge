#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    int n =0;
    cout<< "Please enter an integer, greater or equal to 2: "<<endl;
    cin >> n;

    // length of first line
    int firstline = n*2-1;

    cout<< string(n*2-1, '*')<<endl;

    // space we put on each corner
    int cornerspace = 1;

    // midspace is first line - empty space on each side - star on each side
    int midspace = firstline - (cornerspace*2) - 2;

    // for loop from length = n-1 until length = 2
    for(int i = n-1; i>=2 ; i--)
    {
        cout<< string(cornerspace, ' ') <<"*"<< string(midspace, ' ') << "*"<< string(cornerspace, ' ')<<endl;
        cornerspace +=1;
        midspace-=2; // since cornerspace increase one on each side, midspace is reduced by one on each side
    }

    // last star
    cornerspace = firstline /2;
    cout<< string(cornerspace, ' ') << "*" << string(cornerspace, ' ')<<endl;
}

