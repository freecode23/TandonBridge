/*
Author : Sherly Hartono
Hw3 Question 2:

Write a program that:
• Asks the user for their name.
• Asks the user to input their graduation year.
• Asks the user to input the current year.

Assume the student is in a four-year undergraduate program. Display the current status the student is in. 
ossible status include: not in college yet, freshman, sophomore, junior, senior, graduated.

Note: If graduation year equals to current year, status is ‘Graduated’;
if graduation year is four years after current year, status is ‘Freshman’, etc.

Your program should interact with the user exactly as it shows in the following example:
Please enter your name: Jessica
Please enter your graduation year: 2019
Please enter current year: 2015
Jessica, you are a Freshman
*/

# include <iostream>
# include <string>

using namespace std;

int main()
{
    int gradYear,currentYear;
    string name, status;
    cout << "Please enter your name: " <<endl;
    cin >> name;

    cout << "Please enter your graduation year: " <<endl;
    cin >> gradYear;

    cout << "Please enter current year: "<<endl;
    cin >> currentYear;


    if(gradYear == currentYear)
    {
        status  = "Graduated";
    }
    else if(gradYear == (currentYear + 4)) // equal to four years after current year
    {
        status = "a Freshman";
    }
    else if(gradYear > (currentYear + 4))
    {
        status = "not in college yet";
    }
    else if(gradYear == (currentYear + 3)) // 3 years after current year
    {
        status = "a Sophomore";
    }
    else if(gradYear == (currentYear + 2))
    {
        status = "a Junior";
    }
    else if(gradYear == (currentYear + 1))
    {
        status = "a Senior";
    }
    cout << name << ", you are " << status << endl;
}