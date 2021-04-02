#include <iostream>

using namespace std;

// Note 1
class B; //pre-definiton

class A
{
	int x;

public:
	A(int newx = 0) : x(newx) {} // constructor initialize x to be newx
	//no accessor function for x!!!
	friend class B;
};


class B
{
	A amember;

public:
	int getX() const { return amember.x; }
};

// Note 2
class Elephant
{
	int *arr;
	int count;
	int capacity;

public:
	// 1. constructor
	Elephant() : arr(new int[200000000]), count(0), capacity(200000000) {}

	// BIG 3 solutions to avoid memory leak
	// 2.copy constructor
	Elephant(const Elephant &rhs) : arr(new int[200000000]), count(0), capacity(200000000) { *this = rhs; }
	// 3. destructor
	~Elephant() { delete[] arr; }

	// 4. operator overload
	Elephant &operator=(const Elephant &rhs); //must be a member of the class!!!!!
};

Elephant &Elephant::operator=(const Elephant &rhs)
{ //must be a member of the class!!!!!
	if (this == &rhs)
		return *this;
	for (int i = 0; i < capacity; i++)
		arr[i] = rhs.arr[i];
	return *this;
}


// Note 3
class Thing
{
	int *val;

public:
	// 1. constructor
	Thing(int newval = 0) : val(new int(newval)) {}
	Thing(const Thing &rhs) : val(new int(*rhs.val)) {}
	~Thing() { delete val; }


	// 2. getter setter
	void setVal(int newval) { *val = newval; } //inline function
	int getVal() const { return *val; }	 //const-ify the calling object , make sure object cannot be modified
	const int getVal2() { return *val; } //const-ify the return value!
										 //friend Thing operator-(const Thing& lhs, const Thing& rhs);

	// 3. operator overload member
	Thing &operator=(const Thing &rhs);		   //must be a member of the class!!!!!
	Thing operator+(const Thing &rhs) const;
};

// 3. a
// Operator overload implementation member function
Thing operator-(const Thing &lhs, const Thing &rhs)
{
	//non-member so two parameters!
	Thing temp(lhs.getVal() + rhs.getVal());
	//delete lhs.val;
	return temp;
}

// 3. b
// ReturnValue FunctionName (Parameter1Type Parameter1Name, Parameter2Type Parameter2Name)
Thing &Thing::operator=(const Thing &rhs)
{
	if (this == &rhs) //test for self-assignment!
		return *this;
	*val = *rhs.val;
	return *this;
}

// Note 4
class NewThing
{
public:
	int x;
	int y;
};

// operator overload member 
Thing Thing::operator+(const Thing &rhs) const
{
	Thing temp = *this;
	temp.val += *rhs.val;
	return temp;
}

// operator overload non member
ostream &operator<<(ostream &outs, const Thing &rhs)
{
	outs << rhs.getVal();
	return outs;
}

void func(const Thing &one)
{
	//one.getVal2();
}

void func2(const Elephant &e)
{
	cout << "Bring in da noise, bring in da Func2!" << endl;
}


// main
int main()
{
	cout << "Creating an elephant!" << endl;
	Elephant e1;
	cout << "Now calling the func" << endl;
	func2(e1);
	cout << "Done!" << endl;
	Thing *tptr = new Thing(100);

	cout << *tptr << endl;
	(*tptr).getVal(); // same: tptr->getVal();

	/*
	NewThing one;
	NewThing two;
	one.x = 10;
	one.y = 20;
	//two.x = one.x; two.y = one.y;
	two = one; //Shallow copy!
	Thing t1(5);
	Thing t2(10);
	Thing t3;
	t3 = t1 + t2; // t3.operator=(t1.operator+(t2));
	t3 = t1 - t2; // t3.operator=(operator-(t1,t2));
	t2 = t3; // t2.operator=(t3);
	t1 = t2 = t3;
	//(        cout   << endl; // operator<<(cout,endl);
	//operator<<(cout, t3);
	((cout << t3) << endl);
	*/
}