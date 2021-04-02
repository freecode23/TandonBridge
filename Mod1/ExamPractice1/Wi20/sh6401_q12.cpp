/*Q11
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int numStudents;
    int studentCounter = 0;
    cout << "How many students do you wish to enter?" << endl;
    cin >> numStudents;

    while(numStudents!= 0)
    {
        float grade = 0;
        int gradeCounter = 0;
        float sumGrade = 0;
        cout <<"Enter list of grades, separated by a space. End the grades list by typing -1:" << endl;
        cin >> grade;

        while(grade != -1)
        {
            sumGrade +=  grade;
            gradeCounter++;
            cin >>grade;
        }

        float average = sumGrade / gradeCounter;
        cout << fixed << showpoint << setprecision(1);
        cout << average <<endl;
        numStudents --;
        studentCounter ++;
    }
}