/* 
Author: Sherly Hartono
Hw2
Question3
Suppose John and Bill worked for some time and we want to calculate the total time both of them worked.
Write a program that reads number of days, hours, minutes each of them worked,
and prints the total time both of them worked together as days, hours, minutes.

Hint: Try to adapt the elementary method for addition of numbers to this use.
Your program should interact with the user exactly as it shows in the following example:
Please enter the number of days John has worked: 2
Please enter the number of hours John has worked: 12
Please enter the number of minutes John has worked: 15
Please enter the number of days Bill has worked: 3
Please enter the number of hours Bill has worked: 15
Please enter the number of minutes Bill has worked: 20
The total time both of them worked together is: 6 days, 3 hours and 35 minutes.
*/

# include <iostream>
# include <string>

using namespace std;

int main() {
    int johnDays, johnHours, johnMins, billDays, billHours, billMins;
    // John
    cout << "Please enter the number of days John has worked: " << endl;
    cin >> johnDays;
    cout << "Please enter the number of days John has worked: " << endl;
    cin >> johnHours;
    cout << "Please enter the number of days John has worked: " << endl;
    cin >> johnMins;

    // Bill 
    cout << "Please enter the number of days Bill has worked: " << endl;
    cin >> billDays;
    cout << "Please enter the number of days Bill has worked: " << endl;
    cin >> billHours;
    cout << "Please enter the number of days Bill has worked: " << endl;
    cin >> billMins;


    //mins:
    int totMins = johnMins + billMins; // initial
    int totHours = totMins / 60;        // pass minute to hours
    totMins = totMins % 60;            // remainder minutes 

    //hours:
    totHours += johnHours + billHours; // initial
    int totDays = totHours / 24;         // pass hours to days
    totHours = totHours % 24;            // remainder hours

    // days:
    totDays += johnDays + billDays;

    cout << johnDays << " " << johnHours << " " << johnMins << " " << billDays << " " << billHours << " " << billMins
         << endl;
    cout << "The total time both of them worked together is: " << totDays << " days, " << totHours << " hours and "
         << totMins << " minutes." << endl;
}
