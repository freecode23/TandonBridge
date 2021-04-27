#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void openFile(ifstream &inFileObject);
bool isFoundBinarySearch(vector<string> &the_vector, string nameToSearch, int lo, int hi);


void openFile(ifstream &inFileObject)
{
    string fileName;
    
    cout << "enter file name "<<endl;
    cin >> fileName;

    //try open file:
    inFileObject.open(fileName);
    while(!inFileObject)
    {
        cout << "cannot open file, reenter filename: " << endl;
        cin >> fileName;

        inFileObject.clear();
        inFileObject.open(fileName);
    }
}
