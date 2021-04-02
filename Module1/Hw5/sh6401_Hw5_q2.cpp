/*
* Homework 5
* Question 2
* Author: Sherly Hartono
* Implement a number guessing game.
 * The program should randomly choose an integer between 1 and 100 (inclusive),
 * and have the user try to guess that number.
 * I thought of a number between 1 and 100! Try to guess it.

Range: [1, 100], Number of guesses left: 5
Your guess: 15 Wrong! My number is bigger.

Range: [16, 100], Number of guesses left: 4
 Your guess: 34 Wrong! My number is smaller.

Range: [16, 33], Number of guesses left: 3
Your guess: 23 Congrats! You guessed my number in 3 guesses.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int randomNum;
    int guessNum =0;
    int NumberOfGuesses = 5;
    int loRange = 1;
    int hiRange = 100;

    // seed
    srand(time(0));

    // initialize random numbers from 1 -100:
    randomNum = (rand() %100)+1;
    // cout << "randomNum: " << randomNum <<endl;

    while((guessNum != randomNum)&& (NumberOfGuesses!=0))
    {
        cout << "Range: ["<<loRange<<", " << hiRange<< "], Number of guesses left: "<< NumberOfGuesses <<endl;
        cout << "Your guess:";
        cin >> guessNum;
        NumberOfGuesses --;
        if(guessNum < randomNum)
        {
            // loRange becomes the number greater than guessed number
            cout << "Wrong! My number is bigger." <<endl;
            loRange = guessNum +1;
        }
        else if((guessNum > randomNum))
        {
            cout << "Wrong! My number is smaller."<<endl;
            hiRange = guessNum -1;
        }
        cout << endl;
    }
    // out of while loop means guess is right or number of guesses is 0
    if((NumberOfGuesses == 0)&& (guessNum != randomNum))
    {
        cout << "Out of guesses! My number is " << randomNum <<endl;
    }
    else
    {

        cout << "Congrats! You guessed my number in "<<5-NumberOfGuesses <<" guesses." <<endl;
    }
}