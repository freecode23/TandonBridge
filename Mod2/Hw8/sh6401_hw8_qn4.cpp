/*
Hw 8 Question 4:
Assuming that the actual PIN number is 12345, your program should
interact with the user exactly as it shows in the following examples
(2 different executions of the program):
Please enter your PIN according to the following mapping:
PIN: 0 1 2 3 4 5 6 7 8 9 (index)
NUM: 3 2 3 1 1 3 2 2 1 3  (array)
23113
Your PIN is correct

Please enter your PIN according to the following mapping:
PIN: 0 1 2 3 4 5 6 7 8 9
NUM: 1 1 2 3 1 2 2 3 3 3
23113
Your PIN is not correct
*/

#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int const DISPLAY_SIZE = 10;
int const PIN_SIZE = 5;
int const PIN = 01234;

bool isPinMatch(int enteredPin[], int correctPinRep[]);
void generateArrayOfRandomNum(int num[]);

void generateArrayOfRandomNum(int num[])
{
    // 3. create array of random number
    for (int index = 0; index < DISPLAY_SIZE; index++)
    {
        num[index] = (rand() % 3) + 1;
    }
}

bool isPinMatch(int enteredPin[], int correctPinRep[])
{
    int correctCounter = 0;
    for (int index = 0; index < PIN_SIZE; index++)
    {
        if (enteredPin[index] != correctPinRep[index])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // 1. initialize array and random number
    int num[DISPLAY_SIZE];

    // 2. seed
    srand(time(0));

    // 3. create array of random number
    generateArrayOfRandomNum(num);

    // 4. Display
    // PIN
    cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "NUM: ";
    // NUM
    for (int index = 0; index < DISPLAY_SIZE; index++)
    {
        cout << num[index] << " ";
    }
    cout << endl;

    // 5. get pin
    int enteredPin[PIN_SIZE];
    string digitString;
    cin >> digitString;

    // 6. create array of enteredPin
    for (int index = 0; index < PIN_SIZE; index++)
    {
        // convert char to integer by subtracting char with '0'
        enteredPin[index] = digitString[index] - '0';
    }

    // 7. generate correct pin representation array
    int correctPinRep[5];
    for (int i = 0; i < PIN_SIZE; i++)
    {
        correctPinRep[i] = num[i + 1];
    }

    // 8. check match
    if (isPinMatch(enteredPin, correctPinRep))
    {
        cout << "Your PIN is correct" << endl;
    }
    else
    {
        cout << "Your PIN is incorrect" << endl;
    }
}