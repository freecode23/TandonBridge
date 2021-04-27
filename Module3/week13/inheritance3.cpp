#include <iostream>

using namespace std;

/*
C++ multiple choice question
Assume we have defined a Base class and a Derived class (which derives from Base, obviously)
and the Base class is defined as follows:
Derived class overrides the printData function to look like
(we’re just showing the overridden function, not the rest of the class):

what is the output from the program:
a) Base
b) Derived
c) Base Derived
d) Derived Base
e) None of the above
*/

class Base
{
public:
    void printData() { cout << "Base" << endl; }
    

};

class Derived : public Base
{
    public:
    void printData() { cout << "Derived" << endl; }
};

// A non-member function called printIt which looks like:
void printIt(Base *b)
{
    // Base *b = &d
    // b points to a derived object
    // since it's not a virtual function
    // it will print base
    b->printData();
}

int main()
{
    Derived d;
    printIt(&d);
}
