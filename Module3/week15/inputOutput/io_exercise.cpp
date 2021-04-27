#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
bool isFoundBinarySearch(vector<string> the_vector, string nameToSearch, int lo, int hi);
void openInputFile(ifstream &inFileObject);

int main()
{
    ifstream inFileObject1;
    openInputFile(inFileObject1);

    // create empty vector of strings
    vector<string> vectorOfNames;
    string name;

    int hiIndex = vectorOfNames.size() - 1;
    while (getline(inFileObject1, name)) // quit when it reach the end of file
    {
        // get size of vector
        if (!isFoundBinarySearch(vectorOfNames, name, 0, hiIndex))
        {
            // store this variable onto vector
            vectorOfNames.push_back(name);
            hiIndex = vectorOfNames.size() - 1;
        }
    }

    for (string person : vectorOfNames)
    {
        cout << person << endl;
    }
}

bool isFoundBinarySearch(vector<string> the_vector, string nameToSearch, int lo, int hi)
{
    int mid = (lo + hi) / 2;
    // base case is not found
    if (lo > hi)
        return false;

    if (the_vector[mid] == nameToSearch)
    {
        return true;
    }
    else if (the_vector[mid] > nameToSearch)
    {
        // search left
        return isFoundBinarySearch(the_vector, nameToSearch, lo, mid-1);
    }
    else
    {
        // search right
        return isFoundBinarySearch(the_vector, nameToSearch, mid + 1, hi);
    }
}

void openInputFile(ifstream &inFileObject)
{
    string filename;

    cout << "enter file name: " << endl;
    cin >> filename;

    // try open
    inFileObject.open(filename);

    // while its not open keeep asking
    while (!inFileObject)
    {
        cout << "File failed to open. Please enter filename again: " << endl;
        cin >> filename;

        // try to open again
        // clear flags first
        inFileObject.clear();
        inFileObject.open(filename);
    }
}
