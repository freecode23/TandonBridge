#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <class T>
class LinkedList; //Pre-Definition to make Friend work in Node

struct Pair
{
	int pair_id;
	int pair_hour;
};

// 1. Employee struct
class Employee
{
private:
	int id;
	string name;
	double pay_rate;
	int total_hours = 0;
	double salary = 0;

public:
	Employee();
	Employee(int the_id, string the_name, double the_pay_rate, int the_total_hours , double salary);

	int getId() const { return id; };
	string getName() const { return name; };
	double getPayRate() const { return pay_rate; };
	int getTotalHours() const { return total_hours; };
	int getSalary() const { return salary; };
};

/********************
2. Node Class
********************/

// 1. Node Class
template <class T>
class Node
{
	T data;
	Node<T> *next;
	Node<T> *prev;

public:
	// signature with argument list
	Node(const T &newdata = T(), Node<T> *newnext = nullptr, Node<T> *newprev = nullptr) : // initialize data
																						   data(newdata), next(newnext), prev(newprev)
	{
	}

	void printNodeData();
	T getNodeData();
	friend class LinkedList<T>;
};

/********************
3. LinkedList Class
********************/
// 2. LinkedList Class
template <class T>
class LinkedList
{
	Node<T> *head;
	Node<T> *tail;

public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList<T> &rhs);
	LinkedList<T> &operator=(const LinkedList<T> &rhs);

	// delete all
	void clear()
	{
		while (!isEmpty())
			pop_front();
	}

	// insert to to back
	void push_back(const T &data)
	{
		// connect the tail
		tail->prev = new Node<T>(data, tail, tail->prev);

		// connect the tail's previous
		tail->prev->prev->next = tail->prev;
	}

	// insert at heads
	void push_front(const T &data)
	{
		// connect the head
		head->next = new Node<T>(data, head->next, head);

		// connect the node after head
		head->next->next->prev = head->next;
	}

	T pop_back();
	T pop_front();

	T *searchListByID(int id);
	int size();
	bool isEmpty() { return head->next == tail; }
	void printList();
	void sortList();
};

/*
===============================
		IMPLEMENTATION
===============================
*/
/********************
1. Employee Implement
********************/
// 1. default ctor
Employee::Employee()
{
	id = 0;
	pay_rate = 0;
	total_hours = 0;
	name = "a";
}

// 2. parameterized ctor
Employee::Employee(int the_id, string the_name, double the_pay_rate, int the_total_hours, double the_salary)
{
	id = the_id;
	pay_rate = the_pay_rate;
	total_hours = the_total_hours;
	name = the_name;
	salary = the_salary;
}

/********************
2. Node Implement
********************/
template <typename T>
void Node<T>::printNodeData()
{
	cout << data.getId() << "\t"
		 << data.getName() << "\t"
		 << data.getPayRate() << "\t"
		 << data.getTotalHours() << "\t"
		 << data.getSalary() << "\t"
		 << endl;
}

template <typename T>
T Node<T>::getNodeData()
{
	return this->data;
}

/********************
2. LinkedList Impelemet
********************/
// 1. assignment operator
template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
	if (this == &rhs)
		return *this;
	clear();
	Node<T> *ptr = rhs.head->next;
	while (ptr != rhs.tail)
	{
		push_back(ptr->data);
	}
	return *this;
}

// 2. get size
template <class T>
int LinkedList<T>::size()
{
	Node<T> *ptr = head->next;
	int count = 0;
	while (ptr != tail)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}

// 3. remove back
template <class T>
T LinkedList<T>::pop_back()
{
	if (tail->prev == head) //empty list!
		return T();			//not sure what to do here?  User did something dumb.
	T retval = tail->prev->data;
	Node<T> *nodeToDelete = tail->prev;
	tail->prev = nodeToDelete->prev;
	nodeToDelete->prev->next = nodeToDelete->next;
	delete nodeToDelete;
	return retval;
}

// 4. delete head
template <class T>
T LinkedList<T>::pop_front()
{
	if (tail->prev == head) //empty list!
		return T();			//not sure what to do here?  User did something dumb.
	T retval = head->next->data;
	Node<T> *nodeToDelete = head->next;
	head->next = nodeToDelete->next;
	head->next->prev = head;
	delete nodeToDelete;
	return retval;
}

// 5. destructor
template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
	delete head;
	delete tail;
}

//constructor 1
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &rhs)
{
	head = new Node<T>();
	tail = new Node<T>();
	head->next = tail;
	tail->prev = head;
	*this = rhs; //call to the assignment operator!!!
}

//constructor 2
template <class T>
LinkedList<T>::LinkedList()
{ //build two nodes, as "Dummies" for teh sake of making things easier
	head = new Node<T>();
	tail = new Node<T>();
	head->next = tail;
	tail->prev = head;
}

// print list
template <typename T>
void LinkedList<T>::printList()
{
	Node<T> *currentPtr = head->next;

	while (currentPtr != tail)
	{
		currentPtr->printNodeData();
		currentPtr = currentPtr->next;
	}
	cout << endl;
}

// sort list
template <typename T>
void LinkedList<T>::sortList()
{
	Node<T> *currentPtr = head->next;
	Node<T> *iterationPtr = head->next->next;
	Node<T> *paidMostPtr = currentPtr;

	// while(currentPtr != tail)
	// {

	// }


}

// template <class T>
// void selectionSort(vector<T>& v){ //O(N^2)
// 	for (int i = 0; i < v.size(); i++){
// 		int indexOfLowest = i;
// 		for (int j = i + 1; j < v.size(); j++) // j is after i
// 			if (v[j] < v[indexOfLowest])
// 				indexOfLowest = j;
// 		T temp = v[i];
// 		v[i] = v[indexOfLowest];
// 		v[indexOfLowest] = temp;
// 	}
// }

/*
open Input File
*/
void openInputFile(ifstream &fileReader)
{
	string filename;
	cin >> filename;
	fileReader.open(filename);
	while (!fileReader) // while its not open
	{
		cout << "Error, cannot openfile. enter filename again: \n";
		cin >> filename;
		fileReader.clear();
		fileReader.open(filename);
	}
}

bool isIDExist(vector<Pair> pairVector, int id)
{
	for (int i = 0; i < pairVector.size(); i++)
	{
		if (pairVector[i].pair_id == id)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	// create empty linked list of NODES of Employee Type
	LinkedList<Employee> *employeeList = new LinkedList<Employee>();

	// 1. number of hours info
	ifstream fileReader1;
	cout << "1. Enter filename for **total hours** to get input: \n";
	openInputFile(fileReader1);

	// prepare variable
	int id = 0;
	int hour = 0;
	vector<Pair> pairVector;
	Pair pair1;

	//2. read from hours.txt file
	while (fileReader1 >> id)
	{
		fileReader1 >> hour;
		// check if id already exists
		if (isIDExist(pairVector, id))
		{
			for (int i = 0; i < pairVector.size(); i++) // search for the index
				if (pairVector[i].pair_id == id)
				{
					pairVector[i].pair_hour += hour; // increment the hour
				}
		}
		else
		{
			pair1.pair_id = id;
			pair1.pair_hour = hour;
			pairVector.push_back(pair1);
		}
		
	}

	fileReader1.close();

	ifstream fileReader2;
	// 3. read employee info
	cout << "1. Enter filename for **Employees** to get input: \n";
	// - open
	openInputFile(fileReader2);

	double pay_rate;
	string name;
	double salary;
	while (fileReader2 >> id)
	{
		// 1. payrate
		fileReader2 >> pay_rate;
		// 2. name
		getline(fileReader2, name);

		// 3. total_hour
		for(int i=0; i < pairVector.size(); i++)
		{
			if(pairVector[i].pair_id ==id)
			{
				hour = pairVector[i].pair_hour;
				salary = hour * pay_rate;
			}
		}
		// 4. push back to linked list
		employeeList->push_back(Employee(id, name, pay_rate, hour, salary));

	}
	fileReader2.close();
	employeeList->printList();

	// 4. sort linkedlist
}
