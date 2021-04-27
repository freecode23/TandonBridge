#include <iostream>
using namespace std;
// Given a base class pointer (Base * bptr) to a derived
// class object is the following allowed or not allowed?
//Base b = *bptr;
// a. Always allowed

class Parent 
{
    public:
        Parent():money(200){};
        int money;
};

class Child : public Parent
{
    public:
        Child(): toy(1){};
        int toy;
};

int main()
{
    Parent * parentPtr = new Child();
    Parent p = *parentPtr;

    cout << "money " << p.money << endl;
    // cout << "toy " << p.toy << endl;


}