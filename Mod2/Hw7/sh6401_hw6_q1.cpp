/*
Name: Sherly Hartono
Hw 7
Question 1
Implement a function:
int printMonthCalender(int numOfDays, int startingDay)
This function is given two parameters:	
• numOfDays - The number of	days in	the	month	
• startingDay – a number 1-7 that represents the day in the	week of the	first day	
in	that month (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).		
*/

#include <iostream>

using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
void printYearCalendar(int year, int startingDay);
bool isLeap(int year);

int main()
{
    int year;
    int startingDay;
    cout << "Enter year followed by starting day: "<< endl;
    cin >> year >> startingDay;

    printYearCalendar(year, startingDay);
}

// a)
int printMonthCalendar(int numOfDays, int startingDay)
{
    cout << "Mon \t"
         << "Tues \t"
         << "Wed \t"
         << "Thr \t"
         << "Fri \t"
         << "Sat \t"
         << "Sun" << endl;

    // first line/week
    // print space
    int dayOfWeek = 1;
    int numOfSpace = 1;
    while ((dayOfWeek <= 7) && (numOfSpace <= startingDay - 1))
    {
        cout << " \t";
        dayOfWeek++;
        numOfSpace++;
    }

    int date = 1;
    // print num
    while (dayOfWeek <= 7)
    {
        cout << date << " \t";
        date++;
        dayOfWeek++;
    }
    cout << endl;

    // second week onwards
    // while we havent finish the month

    int dayOfweekCount = 1;
    while (date <= numOfDays)
    {
        dayOfweekCount = 1;

        // print date per week
        while ((dayOfweekCount <= 7) && (date <= numOfDays))
        {
            cout << date << " \t";
            dayOfweekCount++;
            date++;
        }
        // out of while loop we reach the end of the week and we havent finished the month
        cout << endl;
    }
    return dayOfweekCount;
}

// b) A function that takes	in a year as input and return true if the year is a	leap year,
// return false	otherwise.
// For example, 1896, 1904, and 2000 were leap years but 1900 was not.
bool isLeap(int year)
{
    // divisible by 4
    bool divBy4 = (year % 4 == 0);

    // divisible by 100
    bool divBy100 = (year % 100 == 0);

    // divisible by 400
    bool divBy400 = (year % 400 == 0);
    return ((divBy4 && !divBy100) || (divBy100 && divBy400));
}

/* c) void printYearCalender(int year, int startingDay)
This function is given two parameters:
• year – an integer that represents a year (e.g. 2016)
• startingDay – a number 1-7 that represents the day in the week of 1/1 in that year (1 for Monday, 2 for
Tuesday, 3 for Wednesday, etc.).
The function should use the functions from sections (a) and (b) in order to print a
formatted yearly calendar of that year.
*/

void printYearCalendar(int year, int startingDay)
{
    int month = 1;
    int dayPerMonth;

    // loop 12 times
    while (month <= 12)
    {
        switch (month)
        {
        case 1:
            cout << "January" ;
            dayPerMonth = 31;
            break;

        case 2:
            cout << "February";
            if (isLeap(year))
            {
                dayPerMonth = 29;
            }
            else
            {
                dayPerMonth = 28;
            }
            break;
        case 3:
            cout << "March";
            dayPerMonth = 31;
            break;
        case 4:
            cout << "April";
            dayPerMonth = 30;
            break;
        case 5:
            cout << "May";
            dayPerMonth = 31;
            break;
        case 6:
            cout << "June";
            dayPerMonth = 30;
            break;
        case 7:
            cout << "July";
            dayPerMonth = 31;
            break;
        case 8:
            cout << "August";
            dayPerMonth = 31;
            break;
        case 9:
            cout << "September";
            dayPerMonth = 30;
            break;
        case 10:
            cout << "October";
            dayPerMonth = 31;
            break;
        case 11:
            cout << "November";
            dayPerMonth = 30;
            break;
        case 12:
            cout << "December";
            dayPerMonth = 31;
            break;
        }
        cout << " "<< year << endl;
        startingDay = printMonthCalendar(dayPerMonth, startingDay);
        cout << endl;
        month++;
    }
}