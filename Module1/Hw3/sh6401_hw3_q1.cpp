/*
Author : Sherly Hartono
Hw3Question 1:

Write a program that computes how much a customer has to pay after purchasing two items. 
The price is calculated according to the following rules:
• Buy one get one half off promotion: the lower price item is half price.
• If the customer is club card member, additional 10% off.
• Tax is added.

Inputs to the program include:
• Two items’ prices
• Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)
• Tax rate (User enters the percentage as a number; for example they enter 8.25 if the tax rate is 8.25%)

Program displays:
• Base price - the price before the discounts and taxes
• Price after discounts - the price after the buy one get one half off promotion
  and the member’s discount, if applicable
• Total price – the amount of money the customer has to pay (after tax).
Your program should interact with the user exactly as it shows in the following example:
Enter price of first item: 10
Enter price of second item: 20
Does customer have a club card? (Y/N): y
Enter tax rate, e.g. 5.5 for 5.5% tax: 8.25
Base price: 30.0
Price after discounts: 22.5
Total price: 24.35625
*/

#include <iostream>
#include <string>
using namespace std;

const float HALF_OFF = 0.5;
const float MEMBER_TEN_PERCENT_OFF = 0.9;

int main()
{
    float price1, price2;
    char ownClubCard;
    float taxRate, basePrice, totalPrice;

    // Get all inputs:
    cout << "Enter price of first item: ";
    cin >> price1;

    cout << "Enter price of second item: ";
    cin >> price2;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> ownClubCard;
    ownClubCard = toupper(ownClubCard);

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    basePrice = price1 + price2;
    cout << "Base price: " << basePrice << endl;

    // Calculation:
    // 1. buy 1 get 1 half off
    if (price1 < price2)
    {
        price1 = HALF_OFF * price1;
    }
    else
    {
        price2 = HALF_OFF * price2;
    }

    totalPrice = price1 + price2;
    // 2. club member discount
    if (ownClubCard == 'Y')
    {
        totalPrice = MEMBER_TEN_PERCENT_OFF * totalPrice;
    }

    cout << "Price after discounts: " << totalPrice << endl;

    // 3. add tax rate
    totalPrice += (taxRate / 100) * totalPrice;

    cout.precision(5);
    cout << "Total price: " << totalPrice << endl;
}