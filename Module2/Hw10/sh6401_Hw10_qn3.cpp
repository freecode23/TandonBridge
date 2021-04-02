/*
Name: Sherly
Hw 10
Qn 3
a program that reads from the user a sequence of positive integers ending with -1,
and another positive integer num that the user wishes to search for.
The program should then print all the line numbers in sequence entered by the user,
that contain num, or a message saying that num does not show at all in the sequence.
*/

#include <iostream>
#include <vector>

using namespace std;
// a) Array functions
void printArray(int array[], int arrSize);
void addStringToIntegerArray(string numString, int *intArray, int arrSize);
void searchNumInArray(int *intArray, int numToSearch, int arrSize);
bool isNumExistsInArray(int *intArray, int numToSearch, int arrSize);

// b) Vector functions
void printVectorInt(vector<int> vector);
void searchNumInVector(vector<int> vector1, int numToSearch);
bool isNumExistsInVector(vector<int> vector1, int numToSearch);


// a) Array functions
void printArray(int array[], int arrSize)
{
    cout << "printArray" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void searchNumInArray(int *intArray, int numToSearch, int arrSize)
{
    string numsToPrint = "";
    cout << numToSearch << " shows in lines ";
    for (int i = 0; i < arrSize; i++)
    {
        if (intArray[i] == numToSearch)
        {
            string digitString = to_string(i + 1);
            numsToPrint = numsToPrint + ", " + digitString;
        }
    }
    // replace last coma
    numsToPrint = numsToPrint.substr(2);
    cout << numsToPrint << "." << endl;
}

void addStringToIntegerArray(string numString, int *intArray, int arrSize)
{

    // loop trhough numString
    int sentenceIndex = 0;
    int arrayIndex = 0;

    int spaceIndex = numString.find(" ", sentenceIndex);

    // while there are still spaces to find
    while (spaceIndex != string::npos)
    {
        int numLength = spaceIndex - sentenceIndex;

        // get digit as string
        string singleNumString = numString.substr(sentenceIndex, numLength);

        // convert to integer
        int num = stoi(singleNumString);

        // add to array
        intArray[arrayIndex] = num;

        //increment
        arrayIndex++;
        sentenceIndex = spaceIndex + 1;

        spaceIndex = numString.find(" ", sentenceIndex);
    }
}

bool isNumExistsInArray(int *intArray, int numToSearch, int arrSize)
{
    int i = 0;
    while(i < arrSize)
    {
        if(numToSearch == intArray[i])
        {
            return true;
        }
        i++;
    }
    return false;
}

// a) array
void main1()
{
    string numString = "";
    string num = "";
    int arrSize = 0;

    cout << "a) using array"<<endl;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    // 1. get user input as strings of numbers
    cin >> num;
    numString = num;
    while (num != "-1")
    {
        arrSize++;
        cin >> num;
        numString = numString + " " + num;
    }
    int *intArray = new int[arrSize];

    // 2. add string to integer array
    addStringToIntegerArray(numString, intArray, arrSize);

    int numToSearch = 0;
    cout << "Please enter a the number you want to search" << endl;
    cin >> numToSearch;

    // 3. If number exists
    if (isNumExistsInArray(intArray, numToSearch, arrSize))
    {
        // 4. print out the index
        searchNumInArray(intArray, numToSearch, arrSize);
    }
    else
    {
        cout << numToSearch << " is not present in any lines" << endl;
    }
    delete[] intArray;
    intArray = nullptr;
}


// b) Vector functions
void printVectorInt(vector<int> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        // print number
        cout << vector[i];

        if (i == vector.size() - 1)
        {
            cout << "." << endl;
        }
        else
        {
            cout << ", ";
        }
    }
}

void searchNumInVector(vector<int> vector1, int numToSearch)
{
    vector<int> indexVectorOfNumToSearch;
    for (int i = 0; i < vector1.size(); i++)
    {
        if (numToSearch == vector1[i])
        {
            indexVectorOfNumToSearch.push_back(i + 1);
        }
    }
    cout << numToSearch << " shows in lines ";
    // print missing number
    printVectorInt(indexVectorOfNumToSearch);
}

bool isNumExistsInVector(vector<int> vector1, int numToSearch)
{
    int i = 0;
    while (i < vector1.size())
    {
        if (numToSearch == vector1[i])
        {
            return true;
        }
        i++;
    }
    return false;
}



// a) array
void main1()
{
    string numString = "";
    string num = "";
    int arrSize = 0;

    cout << "a) using array"<<endl;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    // 1. get user input as strings of numbers
    cin >> num;
    numString = num;
    while (num != "-1")
    {
        arrSize++;
        cin >> num;
        numString = numString + " " + num;
    }
    int *intArray = new int[arrSize];

    // 2. add string to integer array
    addStringToIntegerArray(numString, intArray, arrSize);

    int numToSearch = 0;
    cout << "Please enter a the number you want to search" << endl;
    cin >> numToSearch;

    // 3. If number exists
    if (isNumExistsInArray(intArray, numToSearch, arrSize))
    {
        // 4. print out the index
        searchNumInArray(intArray, numToSearch, arrSize);
    }
    else
    {
        cout << numToSearch << " is not present in any lines" << endl;
    }
    delete[] intArray;
    intArray = nullptr;
}

// b vector
void main2()
{
    vector<int> vector1;
    cout << "b) using vector"<<endl;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;


    // 1. get user input
    int numInput = 0;
    cin >> numInput;
    while (numInput != -1)
    {
        // push numInput into vector
        vector1.push_back(numInput);

        // get new input
        cin >> numInput;
    }

    int numToSearch;
    cout << "Please enter a the number you want to search" << endl;
    cin >> numToSearch;

    // 2. If number exists
    if (isNumExistsInVector(vector1, numToSearch))
    {
        // 3. print out the index
        searchNumInVector(vector1, numToSearch);
    }
    else
    {
        cout << numToSearch << " is not present in any lines" << endl;
    }
}

int main()
{
    // main1();
    main2();
}