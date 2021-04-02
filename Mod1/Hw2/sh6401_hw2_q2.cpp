/*
Author: Sherly Hartono
Hw2
Question 2:
Write a program that asks the user to enter an amount of money in the format of dollars and remaining cents.
The program should calculate and print the minimum number of coins (quarters, dimes, nickels and pennies)
that are equivalent to the given amount.

Hint: In order to find the minimum number of coins,
first find the maximum number of quarters that fit in the given amount of money,
then find the maximum number of dimes that fit in the remaining amount,
and so on.

Your program should interact with the user exactly as it shows in the following example:
Please enter your amount in the format of dollars and cents separated by a space:
4 37
4 dollars and 37 cents are:
17 quarters, 1 dimes, 0 nickels and 2 pennies
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    string amount;
    string delimiter = " ";

    cout << "Please enter your amount in the format of dollars and cents separated by a space: " << endl;
    getline(cin, amount);
    // 1. extract dollar and CENTS:
    int pos = amount.find(delimiter);          // get the position of the dollar
    while (pos == -1) {
        cout << "You are not entering the amount in correct format. Please re-enter: " << endl;
        getline(cin, amount);
        pos = amount.find(delimiter);                         // pos is the position of space in this example is 2
    }
    int dollar = stoi(amount.substr(0, pos));                  // get the dollar index 0 to 1
    int cents = stoi(amount.substr(pos + 1, amount.length()));   // get the cents index 3 to the end

    // 2. Get maximumquarters from the dollar
    float QUARTER_IN_DOLLARS = 0.25;
    int QUARTER_IN_CENTS = 25;
    quarters = dollar / QUARTER_IN_DOLLARS;
    quarters += cents / QUARTER_IN_CENTS;

    // 3. convert remainder cents into dime and nickel
    int remainder_cents = cents % QUARTER_IN_CENTS;
    int ONE_DIME_IN_CENTS = 10;
    int ONE_NICKEL_IN_CENTS = 5;
    // while remainder_cents is not 0:
    while (remainder_cents != 0) {


        if (remainder_cents >= ONE_DIME_IN_CENTS) {
            dimes = remainder_cents / ONE_DIME_IN_CENTS;  // get dimes
            remainder_cents = remainder_cents % ONE_DIME_IN_CENTS;  // update remainder_cents 
        } else if (remainder_cents >= ONE_NICKEL_IN_CENTS) {
            nickels = remainder_cents / ONE_NICKEL_IN_CENTS;   // get nickels
            remainder_cents = remainder_cents % ONE_NICKEL_IN_CENTS;  // update remainder_cents
        } else {
            pennies = remainder_cents;
            remainder_cents = 0;
        }
    }
    cout << dollar << " dollars and " << cents << " cents are: " << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies"
         << endl;
}