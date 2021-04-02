/*
Author: Sherly Hartono
Question 5:
Hw3 
Write a program that prompts for weight (in pounds) and height (in inches) of a person
and prints the weight status of that person.
Your program should interact with the user exactly as it shows in the following example:
 
Please enter weight (in pounds): 135
Please enter height (in inches): 71
The weight status is: Normal

Note: 1 pound is 0.453592 kilograms and 1 inch is 0.0254 meters.
Body mass index (BMI) is a number calculated from a person’s weight
and height using the following formula: 𝑤𝑒𝑖𝑔ℎ𝑡 / ℎ𝑒𝑖𝑔ℎ𝑡^2.
Where 𝑤𝑒𝑖𝑔ℎ𝑡 is in kilograms and ℎ𝑒𝑖𝑔ℎ𝑡 is in meters.

Underweight : Below 18.5
Normal: [18.5,25)
Overweight: [25,30)
Obese: 30 and above

*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const float ONE_POUND_IN_KG = 0.453592;
const float ONE_INCH_IN_M = 0.025;
int main()
{

    float BMI;
    float weightInPounds;
    float heightInInches;
    string status;

    cout << "Please enter weight (in pounds): ";
    cin >> weightInPounds;

    cout << "Please enter height (in inches): ";
    cin >> heightInInches;

    // calculation:
    BMI = (weightInPounds * ONE_POUND_IN_KG) / pow((heightInInches * ONE_INCH_IN_M), 2);
    // cout << BMI << endl;
    bool underweight = BMI < 18.5;
    bool normal = (BMI >= 18.5) && (BMI < 25);
    bool overweight = (BMI >= 25) && (BMI < 30);
    bool obese = BMI >= 30;

    if (underweight)
    {
        status = "Underweight";
    }
    else if (normal)
    {
        status = "Normal";
    }
    else if (overweight)
    {
        status = "Overweight";
    }
    else if (obese)
    {
        status = "Obese";
    }
    cout << "The weight status is: " << status << endl;
}