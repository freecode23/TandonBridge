#include <iostream>
using namespace std;

int FOOT_IN_INCHES = 12;
int YARD_IN_INCHES = 3 * FOOT_IN_INCHES;
int MILE_IN_INCHES = 1760 * YARD_IN_INCHES;

int main()
{
    int day = 0;
    int totalInches =0;
    int inchesTravelled;
    cout <<"Enter the number of inches the snail traveled in day #"<< day+1
    << ",\n or type -1 if they reached their destination:"<< endl;
    cin >> inchesTravelled;

    while(inchesTravelled != -1)
    {
        totalInches += inchesTravelled;
        day ++;
        cout <<"Enter the number of inches the snail traveled in day #"<< day+1
        << ",or type -1 if they reached their destination:"<< endl;
        cin >> inchesTravelled;
    }
    // calculate foot
    int nMiles, nYards, remainderInches = 0;
    nMiles = totalInches / MILE_IN_INCHES;
    remainderInches = totalInches % MILE_IN_INCHES;
    cout << "remainderInches: " << remainderInches <<endl;

    nYards = remainderInches / YARD_IN_INCHES;
    cout << "nYards :"<<nYards <<endl;
    remainderInches = totalInches % YARD_IN_INCHES;
    cout << "remainderInches: " << remainderInches <<endl;


//    int remainderInches = totalInches % MILE_IN_YARDS;
    cout << "remainderInches: " << remainderInches <<endl;

    cout << "In " << day <<" days, the snail traveled "<< nMiles << " miles, "<< nYards
    <<" yards and " << remainderInches <<" inches." <<endl;
}