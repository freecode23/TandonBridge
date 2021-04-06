/* CH12 #7
Write a checkbook balancing program.
The program will read in the following for all checks that were not cashed as of the last time you balanced your checkbook:
the number of each check, the amount of the check, and whether or not it has been cashed.
Use an array with a class base type.
The class should be a class for a check.
There should be three member variables to record"
- the check number,
- the check amount,
- and whether or not the check was cashed.
The class for a check will have a member variable of type Money 
as defined in Display 19)
to record the check amount.

So, you will have a class used within a class.
The class for a check should have accessor and mutator functions as well as constructors
and functions for both input and output of a check.

In addition to the checks, the program also reads
- all the deposits, You may want another array to hold the deposits.
- the old and the new account balance.

The new account balance should be the old balance  + all deposits - cashed check.

The program outputs:
- 1. the total of the checks cashed, the total of the deposits,
- 2. what the new balance should be
- 3. how much this figure differs from what the bank says the new balance is.
- Also outputs two lists of checks:
- 4. the checks cashed since the last time you balanced your checkbook
- 5. the checks still not cashed.
Display both lists of checks in sorted order from lowest to highest check number.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

class Money
{
public:
    // 1. Operator overloading
    // 1.1. returns the Money object sum of values of amount1 and amount2
    friend Money operator+(const Money &amount1, const Money &amount2);

    // 1.2. returns amount1 minum amount 2
    friend Money operator-(const Money &amount1, const Money &amount2);

    // 1.3. returns the negative of the value of amount
    friend Money operator-(const Money &amount);

    // 1.4. returns true if amount1 and amount2 have the same value; false otherwise
    friend bool operator==(const Money &amount1, const Money &amount2);

    // 1.5. returns true if amount1 is less than amount2; false otherwise
    friend bool operator<(const Money &amount1, const Money &amount2);

    // 1.6 Overloads the >> operator so it can be used to input values of type
    // Money. Notation for inputting negative amounts is as in − $100.00
    // Precondition: If ins is a file input stream, then ins has already been
    // connected to a file.
    friend istream &operator>>(istream &ins, Money &amount);
    friend ostream &operator<<(ostream &outs, const Money &amount);

    // 2.Constructor
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    Money(long dollars, int cents);
    Money(long dolars);
    Money();

    // 3. Other function
    //Returns the amount of money recorded in the data portion of the calling object
    double get_val() const;

    // variables:
private:
    long all_cents;
};

class Check
{
public:
    // 1. constructor
    Check();
    Check(int checkId, Money checkAmount, bool isCheckCashed);

    // 2. getter
    int getCheckId() const;
    Money getCheckAmount() const;
    bool isCheckCashed() const;

    // 3. setter
    void setCheckId(int checkId);
    void setCheckAmount(int checkAmount);
    void setCheckCashStatus(bool isCheckCashed);

    // 4. overload operator
    friend istream &operator>>(istream &ins, Check &check);
    friend ostream &operator<<(ostream &outs, const Check &check);
    friend Check &operator+(const Check &check1, const Check &check2);
    friend bool operator<(const Check &check1, const Check &check2);

private:
    int id;
    bool isCashed;
    Money amount;
};

int digit_to_int(char c);
void printCheckVector(vector<Check> checkVector);
void printCashedOrUncashedVector(vector<Check> checkVector, bool isPrintCashed);

int main()
{
    // 1. create variables for checks, deposits, old balance, new balance
    vector<Check> checkVector;
    vector<Money> depositVector;

    int depositCount = 0;
    int checkCount = 0;

    Money oldBalance;

    Money depositAmount;
    Check newCheck;

    // 2. GET INPUT
    // - balances
    cout << "Enter old balance (format example: $1000.00): ";
    cin >> oldBalance;

    // - deposit
    cout << "\nHow many deposit do you want to make: ";
    cin >> depositCount;
    int counter = 1;
    while (depositCount != 0)
    {
        cout << "Enter the " << counter << "th deposit amount: ";
        cin >> depositAmount;

        // insert deposit to vector
        depositVector.push_back(depositAmount);
        counter++;
        depositCount--;
    }

    // - checks
    cout << "\nHow many check do you want to write: ";
    cin >> checkCount;
    cout << "Enter in this format: <id> <$amount> <y or n>";
    cout << "\n(e.g. 7783737 $50.00 y)\n";
    counter = 1;
    while (checkCount != 0)
    {
        cout << "Enter the " << counter << "th check: ";
        cin >> newCheck;

        // insert check to checkVector

        checkVector.push_back(newCheck);
        counter++;
        checkCount--;
    }

    sort(checkVector.begin(), checkVector.end());

    // 3. OUTPUT
    // 3.1
    Money totalDeposit;
    for (int i = 0; i < depositVector.size(); i++)
    {
        totalDeposit = totalDeposit + depositVector[i];
    }
    cout << "\n==========SUMMARY==========" <<endl;
    cout << "\nTotal deposit is: \t" << totalDeposit;

    Check totalCheck;
    for (int i = 0; i < checkVector.size(); i++)
    {
        totalCheck = totalCheck + checkVector[i];
    }
    cout << "\nTotal check is: \t" << totalCheck.getCheckAmount();

    //3.2 what the new balance should be (calculated Balance)
    // old balance  + all deposits - cashed check

    Check totalCashedCheck;
    for (int i = 0; i < checkVector.size(); i++)
    {
        if (checkVector[i].isCheckCashed())
        {
            totalCashedCheck = totalCashedCheck + checkVector[i];
        }
    }

    Money bankBalance = oldBalance + totalDeposit - totalCashedCheck.getCheckAmount();
    Money shouldBeBalance = oldBalance + totalDeposit - totalCheck.getCheckAmount();

    // 3.3 How much this figure differs from what the bank says the new balance is.
    // calculatedBalance - newBalance
    Money balanceDifference = bankBalance - shouldBeBalance;
    cout << "\n\nCurrent balance: \t" << bankBalance;
    cout << "\nShould be balance: \t"<< shouldBeBalance;
    cout << "\nBalance differences: \t" << balanceDifference;

    // Also outputs two lists of checks:
    // 3.4 the checks cashed
    cout << "\n\nList of Cashed checks:\n";
    printCashedOrUncashedVector(checkVector, 1);

    // 3.5 the checks still not cashed.
    cout << "\nList of Uncashed checks:\n";
    printCashedOrUncashedVector(checkVector, 0);

    cout << "============END===========" <<endl;
}

// ===========  Check Functions Implementation ===========
// 1. Constructor
// default
Check::Check() : id(0), isCashed(false), amount(){};

// set to value from argument
Check::Check(int checkId, Money checkAmount, bool isCheckCashed)
{
    id = checkId;
    amount = checkAmount;
    isCashed = isCheckCashed;
};

// 2. Getter
int Check::getCheckId() const
{
    return id;
}

Money Check::getCheckAmount() const
{
    return amount;
}

bool Check::isCheckCashed() const
{
    return isCashed;
}

// 3. Setter
void Check::setCheckId(int checkId)
{
    id = checkId;
}

void Check::setCheckAmount(int checkAmount)
{
    amount = checkAmount;
}

void Check::setCheckCashStatus(bool isCheckCashed)
{
    isCashed = isCheckCashed;
}

// 4. Operator overload
// addition
Check &operator+(const Check &check1, const Check &check2)
{
    Check temp;
    temp.amount = check1.amount + check2.amount;
    return temp;
}

bool operator<(const Check &check1, const Check &check2)
{
    return check1.id < check2.id;
}

istream &operator>>(istream &ins, Check &check)
{
    int checkId;
    Money checkAmount;
    char isCheckCashedString;
    bool isCheckCashed;

    // get user input
    ins >> checkId;
    ins >> checkAmount;
    ins >> isCheckCashedString;
    if(tolower(isCheckCashedString) == 'y')
    {
        isCheckCashed = true;
    }
    else
    {
        isCheckCashed = false;
    }

    // set this object's variable
    check.id = checkId;
    check.amount = checkAmount;
    check.isCashed = isCheckCashed;

    return ins;
}

ostream &operator<<(ostream &outs, const Check &check)
{
    outs << check.id << '\t' << check.amount << '\t';

    if (check.isCashed)
    {
        outs << "yes" <<endl;
    }
    else
        outs << "no" <<endl;

    return outs;
}

// =========== Money Functions Implementation ===========
// 1. Constructor
Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) //If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100)
{
    // Body intentionally blank.
    // all_cents is initialized to dollars * 100
}

Money::Money() : all_cents(0)
{
    //Body intentionally blank.
    // all_cents is initialized to dollars * 0
}

// 2. Operator Overload
// 2.1. returns the Money object sum of values of amount1 and amount2
Money operator+(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

// 2.2. returns amount1 minum amount 2
Money operator-(const Money &amount1, const Money &amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

// 2.3. returns amount1
Money operator-(const Money &amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

// 2.4
bool operator==(const Money &amount1, const Money &amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

// 2.5. returns true if amount1 is less than amount2; false otherwise
bool operator<(const Money &amount1, const Money &amount2)
{
    if (amount1.all_cents < amount2.all_cents)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 2.6 >> and <<
// in
istream &operator>>(istream &ins, Money &amount)
{
    char one_char, decimal_point, digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative; //set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;

    //if input is legal, then one_char == '$'
    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

    amount.all_cents = dollars * 100 + cents;
    if (negative)
        amount.all_cents = (amount.all_cents * -1);
    return ins;
}

// out
ostream &operator<<(ostream &outs, const Money &amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "− $" << dollars << '.';
    else

        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

// 3. Other
double Money::get_val() const
{
    return (all_cents * 0.01);
}

// Non Class functions
int digit_to_int(char c)
{
    return (static_cast<int>(c) - (static_cast<int>('0')));
}

void printCheckVector(vector<Check> checkVector)
{
    cout << "ID\t"
         << "Amount\t"
         << "Cashed?\t" << endl;
    for (int i = 0; i < checkVector.size(); i++)
    {
        cout << checkVector[i];
    }
}

void printCashedOrUncashedVector(vector<Check> checkVector, bool isPrintCashed)
{
    cout << "ID\t"
         << "Amount\t"
         << "Cashed?\t" << endl;
    if (isPrintCashed == true)
    {
        for (int i = 0; i < checkVector.size(); i++)
        {
            if (checkVector[i].isCheckCashed())
            {
                cout << checkVector[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < checkVector.size(); i++)
        {
            if (!(checkVector[i].isCheckCashed()))
            {
                cout << checkVector[i];
            }
        }
    }
}