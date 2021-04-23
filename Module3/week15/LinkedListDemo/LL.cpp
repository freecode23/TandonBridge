#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

template <class T>
class LList; //Pre-Definition to make Friend work in LListNode

// 1. Node Class
template <class T>
class LListNode
{
	T data;
	LListNode<T> *next;
	LListNode<T> *prev;

public:
	// signature with argument list
	LListNode(const T &newdata = T(), LListNode<T> *newnext = nullptr, LListNode<T> *newprev = nullptr) :
	// initialize data
				data(newdata), next(newnext), prev(newprev) {}
	friend class LList<T>;
};
// 2. LinkedList Class
template <class T>
class LList
{
	LListNode<T> *head;
	LListNode<T> *tail;

public:
	LList();
	~LList();
	LList(const LList<T> &rhs);
	LList<T> &operator=(const LList<T> &rhs);

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
		tail->prev = new LListNode<T>(data, tail, tail->prev);

		// connect the tail's previous
		tail->prev->prev->next = tail->prev;
	}
	// insert at head
	void push_front(const T &data)
	{
		// connect the head 
		head->next = new LListNode<T>(data, head->next, head);

		// connect the node after head
		head->next->next->prev = head->next;
	}

	T pop_back();
	T pop_front();
	int size();
	bool isEmpty() { return head->next == tail; }
};

// 3. Linked list implementation
template <class T>
LList<T> &LList<T>::operator=(const LList<T> &rhs)
{
	if (this == &rhs)
		return *this;
	clear();
	LListNode<T> *ptr = rhs.head->next;
	while (ptr != rhs.tail)
	{
		push_back(ptr->data);
	}
	return *this;
}
template <class T>
int LList<T>::size()
{
	LListNode<T> *ptr = head->next;
	int count = 0;
	while (ptr != tail)
	{
		count++;
		ptr = ptr->next;
	}
	return count;
}
template <class T>
T LList<T>::pop_back()
{
	if (tail->prev == head) //empty list!
		return T();			//not sure what to do here?  User did something dumb.
	T retval = tail->prev->data;
	LListNode<T> *nodeToDelete = tail->prev;
	tail->prev = nodeToDelete->prev;
	nodeToDelete->prev->next = nodeToDelete->next;
	delete nodeToDelete;
	return retval;
}

// delete head
template <class T>
T LList<T>::pop_front()
{
	if (tail->prev == head) //empty list!
		return T();			//not sure what to do here?  User did something dumb.
	T retval = head->next->data;
	LListNode<T> *nodeToDelete = head->next;
	head->next = nodeToDelete->next;
	head->next->prev = head;
	delete nodeToDelete;
	return retval;
}
template <class T>
LList<T>::~LList()
{
	clear();
	delete head;
	delete tail;
}

//constructor 1
template <class T>
LList<T>::LList(const LList<T> &rhs)
{
	head = new LListNode<T>();
	tail = new LListNode<T>();
	head->next = tail;
	tail->prev = head;
	*this = rhs; //call to the assignment operator!!!
}
template <class T>
LList<T>::LList()
{ //build two nodes, as "Dummies" for teh sake of making things easier
	head = new LListNode<T>();
	tail = new LListNode<T>();
	head->next = tail;
	tail->prev = head;
}

void func(ostream &outs)
{
	outs << "Hello world!" << endl;
}

void openInputFile(ifstream &inFile)
{
	string filename;
	cout << "What filename would you like to open: ";
	cin >> filename; // get file name
	inFile.open(filename); //open
	while (!inFile) // check if its not open
	{
		cout << "Bad filename!" << endl;
		cout << "What filename would you like to open: ";
		cin >> filename;
		inFile.clear(); //release all flags!
		inFile.open(filename);
	}
}

template <class T, class S>
class Pair
{
public:
	T first;
	S second;
};

int main()
{
	// 1. LinkedList
	list<int> myList;
	myList.push_back(100);
	myList.push_back(1000);
	//cout << myList[0] << endl; //NO such [] operator!!!!
	for (list<int>::iterator i = myList.begin(); i != myList.end(); i++) // i++ is not incrementing an integer, it's advancing an iterator!!!
		cout << *i << endl;												 //i is NOT a pointer, it's an iterator!!!

	// 2. Output
	// create output object and open it
	ofstream outFile("output.txt");

	// output hello world to file
	func(outFile);

	//output hellow world to cout
	func(cout);

	// 3. Input
	// create input object
	ifstream inFile;

	// open and check if it exist
	openInputFile(inFile);
	string line;
	vector<int> values;

	// create pairitem1
	Pair<string, int> item;
	item.first = "Daniel";
	item.second = 100;

	// create pairitem2
	Pair<int, double> item2;
	item2.first = 100;
	item2.second = 5.5;

	// create pair of pair
	Pair<Pair<string, int>, Pair<double, char>> what; //WHAT??????????? Yep, you can do that!
	what.first.first = "Daniel";
	what.first.second = 100;
	what.second.first = 5.5;
	what.second.second = 'A';

	int sum = 0;
	int count = 0;
	// while we can still read from infile object
	int temp = 0;
	while (inFile >> temp)
	{
		sum += temp;
		count++;
		cout << temp << "\t";
		inFile.ignore(1, ' ');
		getline(inFile, line);
		cout << line << endl;
		values.push_back(temp);
	}
	cout << "The average is: " << sum / count << endl;
	system("pause");
	return 0;
}
