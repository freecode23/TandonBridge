/*
Author : Sherly Hartono
Hw3 Question 3:

Write a program that does the following:
• Ask user to input three Real numbers a, b and c.
  They represent the parameters of a quadratic equation 𝑎𝑥^2 + 𝑏𝑥 + 𝑐 = 0
• Classify to one of the following:
    - ’Infinite number of solutions’
        (for example, 0𝑥^2 + 0𝑥 + 0 = 0 has infinite number of solutions)
    - ’No solution’ (for example, 0𝑥^2 + 0𝑥 + 4 = 0 has no solution)
    - ’No real solution’ (for example, 𝑥^2 + 4 = 0 has no real solutions)
    - ’One real solution’
    - ’Two real solutions’
• In cases there are 1 or 2 real solutions, also print the solutions.

Your program should interact with the user exactly as it shows in the following example:
Please enter value of a: 1
Please enter value of b: 4
Please enter value of c: 4
This equation has a single real solution x=-2.0
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    double a, b, c;
    double discriminant;
    double x1, x2;
    string noOfSolution;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;
    discriminant = (b * b) + (-4) * a * c;

    // set precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    // 1. Linear equation
    if (a == 0) {
        if ((b == 0) && (c == 0)) // (a) a,b,c are zero
        {
            noOfSolution = "Infinite number of solutions";
            cout << "This equation has infinite number of solutions" << endl;
        } else if ((b == 0) && (c != 0)) // (b) a,b is zero: 5 = 0
        {
            noOfSolution = "No Solution";
            cout << "This equation has no solutions" << endl;
        } else if ((b != 0) && (c == 0)) // (c) a,c is zero: 2x = 0
        {
            noOfSolution = "One real solution";
            cout << "This equation has a single real solution x=0" << endl;
        } else if ((b != 0) && (c != 0)) // (d) only a is zero: 2x + 1 =0
        {
            noOfSolution = "One real solution";
            x1 = (-c) / b;
            cout << "This equation has a single real solution x=" << x1 << endl;
        }
    }
        // 2. Quadratic equation
    else if (a != 0) {
        // (a) discriminant is positive: 2 solutions
        if (discriminant > 0) {
            noOfSolution = "Two real solutions";
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "This equation has two real solutions x= " << x1 << " or x= " << x2 << endl;
        }
            // (b) discriminant is 0: 1 solution
        else if (discriminant == 0) {
            noOfSolution = "One real solution";
            x1 = (-b + sqrt(discriminant)) / (2 * a);
            cout << "This equation has a single real solution x= " << x1 << endl;
        } else // (c) discriminant is negative
        {
            noOfSolution = "No real solution";
            cout << "This equation has no real solution" << endl;
        }
    }
}
