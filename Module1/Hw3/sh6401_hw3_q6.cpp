/*
Author: Sherly Hartono
Hw3 
Question 6:
Write a program that computes the cost of a long-distance call.
The cost of the call is determined according to the following rate schedule:
• Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a rate of $0.40 per minute.
• Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged at a rate of $0.25 per minute. 
• Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.
The input will consist of the day of the week, the time the call started, and the length of the call in minutes.
e.g Mo 13:30 35

The output will be the cost of the call.

Notes:
1. The time is to be input in 24-hour notation, so the time 1:30 P.M. is input as 13:30
2. The day of the week will be read as one of the following two character string: Mo Tu We Th Fr Sa Su
3. The number of minutes will be input as a positive integer.

*/

#include <iostream>
#include <string>
using namespace std;

// charge in cents per minute
const float CHARGE_8AM_TO_6PM_WEEKDAY = 0.4;
const float CHARGE_NOT_WORKING_HOURS_WEEKDAY = 0.25;
const float CHARGE_WEEKEND = 0.15;
const int   AM_8 = 8;
const int   PM_5 = 17;
const int   PM_6 = 18;

int main()
{
    // input variables
    string day;
    char colon; 
    int hour, min, duration_min;

    // output variables
    float totalCharge;

    cout << "Enter the day of the week, the time the call started, and the length of the call in minutes\n";
    cout << "(e.g. Mo 13:30 35): " << endl;
    cin >> day >> hour >>colon >> min >> duration_min;

    // conditions:
    bool isWeekend = (day == "Sa") || (day == "Su"); 
    // weekday from 8:00AM - 6:00PM (working hours)
    bool isWorkingHours = ((hour >= AM_8) && (hour <= PM_5)) && ((hour <= PM_6) && (min == 0));

    if(isWeekend)
    {
        totalCharge = CHARGE_WEEKEND * duration_min;
    }
    else
    {
        if(isWorkingHours)
        {
            totalCharge = CHARGE_8AM_TO_6PM_WEEKDAY * duration_min;
            cout << "weekday working hours" << endl;
        }
        else
        {
            // weekday from 6:01 PM - 7:59 AM (not working hours)
            totalCharge = CHARGE_NOT_WORKING_HOURS_WEEKDAY * duration_min;
            cout << "weekday not working hours" << endl;
        }
    }
    cout << "total charge is $" << totalCharge << endl;
}