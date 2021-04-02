/*
Author: Sherly Hartono
Hw2
Question 1:
Write a program that asks the user to enter a number of quarters, dimes, nickels and
 pennies and then outputs the monetary value of the coins in the format of dollars
 and remaining cents.
Your program should interact with the user exactly as it shows in the following example:
Please enter number of coins:
# of quarters: 13 # of dimes: 4 # of nickels: 11 # of pennies: 17
The total is 4 dollars and 37 cents
 */

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int quarters, dimes, nickels, pennies;
    float QUARTER_VALUE = 0.25;
    float DIME_VALUE = 0.1;
    float NICKEL_VALUE = 0.05;

    float PENNY_VALUE = 0.01;

    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;

    // calculate:
    float total = quarters * QUARTER_VALUE + dimes * DIME_VALUE +
                  nickels * NICKEL_VALUE + pennies * PENNY_VALUE;
    int integer = (int) total;
    float dec = (total - integer) * 100;
    cout << "The total is " << integer << " dollars and " << dec << " cents" << endl;
}
