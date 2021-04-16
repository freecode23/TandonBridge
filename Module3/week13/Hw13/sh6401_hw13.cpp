/*
Hw 13
Author: Sherly Hartono

Assignents on Polymorphism and Inheritance
Full Description on Readme.MD
*/

#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

const int SIZE = 20;
//===================================
// 1. Classes Declaration
//===================================
//===================================
// Organism
//===================================
class Organism
{
public:
    // ctor
    Organism();
    Organism(int the_row, int the_col);

    // virtual for both ants and bugs
    virtual string getSpecies();
    virtual void move(int direction);
    virtual void breed();

    // virtual for bugs
    virtual int getTimeNotEat();
    virtual void resetTimeNotEat();
    virtual void incrementTimeNotEat();

    // non virtual same for both
    // getter setter
    // 1. timeSurvived
    int getTimeSurvived();
    void incrementTimeSurvived();
    // void resetTimeSurvived();

    // 2. move status
    bool haveThisMoved();
    void setMoveStatus(bool status);

    // 3. position
    int getRow();
    int getCol();

protected:
    int timeSurvived;
    int row;
    int col;
    bool haveMoved;
};
//===================================
// Ant
//===================================
class Ant : public Organism
{
public:
    // ctor
    Ant();
    Ant(int row, int col);

    // others
    virtual void move(int direction);
    virtual void breed();
    virtual string getSpecies();

protected:
    string speciesName = "Ant";
};
//===================================
// Doodlebug
//===================================
class Doodlebug : public Organism
{
public:
    // ctor
    Doodlebug();
    Doodlebug(int row, int col);

    // others
    virtual void move(int direction);
    virtual void breed();
    virtual void starve();
    virtual string getSpecies();

    virtual int getTimeNotEat();
    virtual void incrementTimeNotEat();
    virtual void resetTimeNotEat();

protected:
    string speciesName = "Doodlebug";
    int timeNotEat = 0;
};

// ===================================
// 2. Grid function Declaration
// ===================================
void fillGridWithNull(Organism *array[SIZE][SIZE]);
void fillGridWithSpecies(Organism *array[SIZE][SIZE]);
void displayGrid(Organism *array[SIZE][SIZE]);

void nextTimeStep(Organism *array[SIZE][SIZE]);

void moveAntsInGrid(Organism *array[SIZE][SIZE]); // moveAntsInGrid in the grid randomly
void moveDoodlebugsInGrid(Organism *array[SIZE][SIZE]);

void breedAntsInGrid(Organism *array[SIZE][SIZE]);
void breedDoodlebugsInGrid(Organism *array[SIZE][SIZE]);

void starveDoodlebugsInGrid(Organism *array[SIZE][SIZE]);

void incrementTimeSurvivedInGrid(Organism *array[SIZE][SIZE]);
void resetOrganismMove(Organism *array[SIZE][SIZE]); // reset ants moved status to false after each time step

// check slot
bool isSlotAnt(Organism *organism);
bool isSlotEmpty(Organism *organism);
bool isSlotDoodlebug(Organism *organism);

int main()
{
    // seed
    srand(time(0));

    // 1. initialize SIZE X SIZE grid of pointers to organism object
    Organism *grid[SIZE][SIZE];

    // 2. fill with nullpointer
    fillGridWithNull(grid);

    // 3. fill with SIZE doodles and SIZE0 ant
    fillGridWithSpecies(grid);

    // 4. print grid
    int timeStep = 0;
    cout << "****************TIME STEP = " << timeStep << "******************" << endl;
    displayGrid(grid);

    // SIZE. get user input
    string userInput = "";
    cout << "Press 'enter' to continue or 'q' to exit:" << endl;
    getline(cin, userInput);

    // 6. continue program
    while ((userInput != "q") || (userInput == ""))
    {
        // 1. nextTimeStep()
        nextTimeStep(grid);
        timeStep++;

        cout << "**************** TIME STEP = " << timeStep << " ******************" << endl;

        // 2. display
        displayGrid(grid);

        cout << "Press enter to continue or 'q' to exit:" << endl;
        getline(cin, userInput);
    }
}

//===================================
// IMPLEMENTATION
//===================================
//3. Grid function
//===================================
void fillGridWithNull(Organism *array[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            array[r][c] = nullptr;
        }
    }
}

void fillGridWithSpecies(Organism *array[SIZE][SIZE])
{
    // fill ant (fill SIZE per row only)
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c += 2)
        {
            if (r % 2 == 0)
            { // Fill in rows with even index
                if (c < SIZE/2)
                    array[r][c] = new Ant(r, c);
            }
            else
            { // Fill in rows with odd index
                if (c >= SIZE/2)
                    array[r][c] = new Ant(r, c);
            }
        }
    }
    // fill in SIZE Doodlebugs
    array[0][SIZE/2] = new Doodlebug(0, SIZE/2);
    array[SIZE/2][2] = new Doodlebug(SIZE/2, 2);
    array[0][3] = new Doodlebug(0, 3);
    array[SIZE-3][SIZE-1] = new Doodlebug(SIZE-3, SIZE-1);
    array[SIZE-1][1] = new Doodlebug(SIZE-1, 1);
}

void displayGrid(Organism *array[SIZE][SIZE])
{

    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            // print ant
            // add if its not null condition to prevent segfault
            if (isSlotAnt(array[r][c]))
            {
                cout << "o";
            }
            // print doodle bug
            else if ((array[r][c] != nullptr) && (array[r][c]->getSpecies() == "Doodlebug"))
            {
                cout << "X";
            }
            else // print empty
            {
                cout << "-";
            }
        }
        cout << endl;
    }
}

bool isSlotAnt(Organism *organism)
{
    return ((organism != nullptr) && (organism->getSpecies() == "Ant"));
}
bool isSlotEmpty(Organism *organism)
{
    return (organism == nullptr);
}
bool isSlotDoodlebug(Organism *organism)
{
    return ((organism != nullptr) && (organism->getSpecies() == "Doodlebug"));
}

void nextTimeStep(Organism *array[SIZE][SIZE])
{
    // 1. move bugs
    moveDoodlebugsInGrid(array);

    // 2. move ant
    moveAntsInGrid(array);

    // 3. starve bugs
    starveDoodlebugsInGrid(array);

    // 4. increment time Survived
    incrementTimeSurvivedInGrid(array);

    // SIZE. breed ants
    breedAntsInGrid(array);

    // 6. breed doodlebugs
    breedDoodlebugsInGrid(array);
}
//** Grid MOVE

void moveAntsInGrid(Organism *array[SIZE][SIZE])
{
    // cout << "** ANTS **" << endl;
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            int rUp = r - 1;
            int rDown = r + 1;
            int cLeft = c - 1;
            int cRight = c + 1;

            // initialize random numbers from 1 -SIZE0:
            int direction = (rand() % 4) + 1;

            // if its ants and this ants haven't moved lets try to move it:
            if (isSlotAnt(array[r][c]) && (array[r][c]->haveThisMoved() == false))
            {
                // cout << "col: " << c << endl;
                // 1. if direction is 1 (up)
                if (direction == 1)
                {
                    // cout << "  moving up ";
                    // move if
                    // conditon A: we are not at the top row (r != 0)
                    // AND
                    // conditon B: the destination slot is empty: (array[r-1][c] == nullptr)
                    if ((r != 0) && (isSlotEmpty(array[rUp][c])))
                    {

                        // move 1 ant
                        // - change the row and col in the ants data
                        array[r][c]->move(direction);

                        // - change the object that the pointer in array is pointing to
                        array[(r - 1)][c] = array[r][c];

                        // - now this position is pointing to nothing
                        array[r][c] = nullptr;
                        // cout << "EXEC";
                    }
                    // cout << endl;
                }
                // 2. if direction is 2 (down)
                else if (direction == 2)
                {
                    // conditon A: we are not at the bottom row (r != SIZE-1)
                    // AND
                    // conditon B: the destination slot is empty: (array[r+1][c] == nullptr)

                    // cout << "  moving down ";
                    if ((r != SIZE-1) && (isSlotEmpty(array[rDown][c])))
                    {

                        // - change the row and col in the ants data
                        array[r][c]->move(direction);

                        // - change the object that the pointer in array is pointing to
                        array[(r + 1)][c] = array[r][c];

                        // - now this position is pointing to nothing
                        array[r][c] = nullptr;
                        // cout << "EXEC" << endl;
                    }
                    // cout << endl;
                }
                // 3. if direction is 3 (left)
                else if (direction == 3)
                {
                    // conditon A: we are not at the leftmost row (c != 0)
                    // AND
                    // conditon B: the destination slot is empty: (array[r][c-1] == nullptr)
                    // cout << "  moving left ";
                    if ((c != 0) && (isSlotEmpty(array[r][cLeft])))
                    {
                        array[r][c]->move(direction);
                        array[r][(c - 1)] = array[r][c];
                        array[r][c] = nullptr;
                        // cout << "EXEC";
                    }
                    // cout << endl;
                }
                // 4. if direction is 4 (right)
                else if (direction == 4)
                {
                    // conditon A: we are not at the rightmost row (c != SIZE-1)
                    // AND
                    // conditon B: the destination slot is empty: (array[r][c-1] == nullptr)
                    // cout << "  moving right ";
                    if ((c != SIZE-1) && (isSlotEmpty(array[r][cRight])))
                    {

                        // move 1 ant
                        // - change the row and col in the ants data
                        array[r][c]->move(direction);

                        // - change the object that the pointer in array is pointing to
                        array[r][(c + 1)] = array[r][c];

                        // - now this position is pointing to nothing
                        array[r][c] = nullptr;
                        // cout << "EXEC";
                    }
                    // cout << endl;
                }
            }
        }
    }
    resetOrganismMove(array);
}

void moveDoodlebugsInGrid(Organism *array[SIZE][SIZE])
{
    // cout << "&& DOODLEBUG MOVE &&" << endl;
    // 1st part Try eat ants
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            int rUp = r - 1;
            int rDown = r + 1;
            int cLeft = c - 1;
            int cRight = c + 1;

            // if this is a doodle bug and dug has not moved
            if (isSlotDoodlebug(array[r][c]) && (array[r][c]->haveThisMoved() == false))
            {

                // cout << "at col: " << c << " row: " << r << endl;
                // look for adjacent ant
                if ((r != 0) && (isSlotAnt(array[rUp][c]))) // ant is above
                {
                    //cout << "  - eat top ant" << endl;
                    // ant eaten
                    delete array[rUp][c];
                    //doodlebug move to up
                    array[rUp][c] = array[r][c];
                    array[rUp][c]->setMoveStatus(true);
                    array[r][c] = nullptr;

                    array[rUp][c]->resetTimeNotEat();
                }
                else if ((r != SIZE-1) && (isSlotAnt(array[rDown][c]))) // ant is below
                {
                    // cout << "  - eat bottom ant" << endl;
                    delete array[rDown][c];

                    //doodlebug move to Down
                    array[rDown][c] = array[r][c];
                    array[rDown][c]->setMoveStatus(true);
                    array[r][c] = nullptr;
                    array[rDown][c]->resetTimeNotEat();
                }
                else if ((c != 0) && (isSlotAnt(array[r][cLeft]))) // ant is left
                {
                    // cout << "  - eat left ant" << endl;
                    delete array[r][cLeft];

                    //doodlebug move to Left
                    array[r][cLeft] = array[r][c];
                    array[r][cLeft]->setMoveStatus(true);
                    array[r][c] = nullptr;
                    array[r][cLeft]->resetTimeNotEat();
                }
                else if ((c != SIZE-1) && (isSlotAnt(array[r][cRight]))) // ant is Right
                {
                    // cout << "  - eat right ant" << endl;
                    delete array[r][cRight];
                    //doodlebug move to Right
                    array[r][cRight] = array[r][c];
                    array[r][cRight]->setMoveStatus(true);
                    array[r][c] = nullptr;
                    array[r][cRight]->resetTimeNotEat();
                }
                else
                {   // not eating any ants
                    // cout << "  - not eating ants" << endl;
                    array[r][c]->incrementTimeNotEat();

                    // Part 2 move like ants
                    // if this doodlebug haven't moved lets try to move it:
                    if (array[r][c]->haveThisMoved() == false)
                    {
                        //move randomly
                        int direction = (rand() % 4) + 1;
                        // 1. if direction is 1 (up)
                        if (direction == 1)
                        {
                            // cout << "  - moving up ";
                            if ((r != 0) && (isSlotEmpty(array[rUp][c])))
                            {
                                // move 1 doodlebug
                                array[r][c]->move(direction);
                                array[rUp][c] = array[r][c];
                                // - now this position is pointing to nothing
                                array[r][c] = nullptr;
                                // cout << "  EXEC ";
                            }
                            //cout << endl;
                        }
                        // 2. if direction is 2 (down)
                        else if (direction == 2)
                        {
                            //cout << "  - moving down ";
                            if ((r != SIZE-1) && (isSlotEmpty(array[rDown][c])))
                            {

                                array[r][c]->move(direction);
                                array[rDown][c] = array[r][c];
                                array[r][c] = nullptr;
                                //cout << "  EXEC ";
                            }
                            //cout << endl;
                        }
                        // 3. if direction is 3 (left)
                        else if (direction == 3)
                        {
                            //cout << "  - moving left ";
                            if ((c != 0) && (isSlotEmpty(array[r][cLeft])))
                            {
                                array[r][c]->move(direction);
                                array[r][cLeft] = array[r][c];
                                array[r][c] = nullptr;
                                //cout << "  EXEC ";
                            }
                            //cout << endl;
                        }
                        // 4. if direction is 4 (right)
                        else if (direction == 4)
                        {
                            // cout << "  - moving right ";
                            if ((c != SIZE-1) && (isSlotEmpty(array[r][cRight])))
                            {
                                array[r][c]->move(direction);
                                array[r][cRight] = array[r][c];
                                array[r][c] = nullptr;
                                // cout << "  EXEC ";
                            }
                            // cout << endl;
                        }
                    }
                }
            }
        }
    }
    resetOrganismMove(array);
}

//** Grid BREED
void breedAntsInGrid(Organism *array[SIZE][SIZE])
{
    int numBreed = 0;
    //cout << "=== Ant Breed ===" << endl;
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            int rUp = r - 1;
            int rDown = r + 1;
            int cLeft = c - 1;
            int cRight = c + 1;

            // if (isSlotAnt(array[r][c]))
            // {
            //     cout << "time survived: " << array[r][c]->getTimeSurvived()<<endl;
            // }

            // breed condition:
            // A: slot is ant && B: time Survived is 3
            if ((isSlotAnt(array[r][c])) && (array[r][c]->getTimeSurvived() >= 3))
            {
                // check for any empty adjacent slot
                // 1.if up is empty, and we are not on row 0
                if ((r != 0) && (array[rUp][c] == nullptr))
                {
                    //cout << "   -breed up" << endl;
                    array[r][c]->breed();
                    array[rUp][c] = new Ant(rUp, c);
                    numBreed ++;
                }
                // 2.if down is empty, and we are not on row 4 breed here
                else if ((r != SIZE-1) && (array[rDown][c] == nullptr))
                {
                    //cout << "   -breed down" << endl;
                    array[r][c]->breed();
                    array[rDown][c] = new Ant(rDown, c);
                    numBreed ++;
                }
                // 3.if left is empty, and we are not on column 0 breed here
                else if ((c != 0) && (array[r][cLeft] == nullptr))
                {
                    //cout << "   -breed left" << endl;
                    array[r][c]->breed();
                    array[r][cLeft] = new Ant(r, cLeft);
                    numBreed ++;
                }
                // 4.if right is empty, and we are not on column 4 breed here
                else if ((c != SIZE-1) && (array[r][cRight] == nullptr))
                {
                    //cout << "   -breed right" << endl;
                    array[r][c]->breed();
                    array[r][cRight] = new Ant(r, cRight);
                    numBreed ++;
                }
                
            }
        
        }
    }
    //cout << "total breed: " << numBreed << endl;
}

void breedDoodlebugsInGrid(Organism *array[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (isSlotDoodlebug(array[r][c]) && (array[r][c]->getTimeSurvived() >= 8)) // if its doodlebug that has survived for 8 times
            {
                //cout << "** doodle breed **" << endl;
                int rUp = r - 1;
                int rDown = r + 1;
                int cLeft = c - 1;
                int cRight = c + 1;

                // check for any empty adjacent slot
                // 1.if up is empty, and we are not on row 0
                if ((r != 0) && (array[rUp][c] == nullptr))
                {
                    //cout << "breed up" << endl;
                    array[r][c]->breed();
                    array[rUp][c] = new Doodlebug(rUp, c);
                }
                // 2.if down is empty, and we are not on row 4 breed here
                else if ((r != SIZE-1) && (array[rDown][c] == nullptr))
                {
                    //cout << "breed down" << endl;
                    array[r][c]->breed();
                    array[rDown][c] = new Doodlebug(rDown, c);
                }
                // 3.if left is empty, and we are not on column 0 breed here
                else if ((c != 0) && (array[r][cLeft] == nullptr))
                {
                    //cout << "breed left" << endl;
                    array[r][c]->breed();
                    array[r][cLeft] = new Doodlebug(r, cLeft);
                }
                // 4.if right is empty, and we are not on column 4 breed here
                else if ((c != SIZE-1) && (array[r][cRight] == nullptr))
                {
                    //cout << "breed right" << endl;
                    array[r][c]->breed();
                    array[r][cRight] = new Doodlebug(r, cRight);
                }
            }
        }
    }
}

void starveDoodlebugsInGrid(Organism *array[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (isSlotDoodlebug(array[r][c]) && (array[r][c]->getTimeNotEat() == 3))
            {
                delete array[r][c];
                array[r][c] = nullptr;
            }
        }
    }
}

void resetOrganismMove(Organism *array[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (!(isSlotEmpty(array[r][c]))) // if slot is not empty
            {
                array[r][c]->setMoveStatus(false); // hasmoved is 0
            }
        }
    }
}

void incrementTimeSurvivedInGrid(Organism *array[SIZE][SIZE])
{
    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (!(isSlotEmpty(array[r][c]))) // if slot is not empty
            {
                array[r][c]->incrementTimeSurvived();
            }
        }
    }
}
//===================================
// 4. Organism
//===================================
Organism::Organism()
{
    timeSurvived = 0;
    haveMoved = false;
    row = -1;
    col = -1;
}

Organism::Organism(int the_row, int the_col)
{
    timeSurvived = 0;
    haveMoved = false;
    row = the_row;
    col = the_col;
}

// 1. virtual definition only
void Organism::move(int direction){};
void Organism::breed(){};
string Organism::getSpecies() { return ""; };

int Organism::getTimeNotEat() { return 0; };
void Organism::resetTimeNotEat(){};
void Organism::incrementTimeNotEat(){};

// 2. getter setter
int Organism::getTimeSurvived()
{
    return timeSurvived;
}

bool Organism::haveThisMoved()
{
    return haveMoved;
}

int Organism::getRow() { return row; };

int Organism::getCol() { return col; };

void Organism::setMoveStatus(bool status)
{
    haveMoved = status;
}

void Organism::incrementTimeSurvived()
{
    timeSurvived += 1;
}

//===================================
// 4. Ant
//===================================
Ant::Ant() : Organism(){};

Ant::Ant(int the_row, int the_col) : Organism(the_row, the_col){};

void Ant::move(int direction)
{
    switch (direction)
    {
    case 1: // up
        row -= 1;
        break;
    case 2: // down
        row += 1;
        break;
    case 3: // left
        col -= 1;
        break;
    case 4:
        col += 1;
        break;
    }
    haveMoved = true;
}

void Ant::breed()
{
    timeSurvived = 0;
}

string Ant::getSpecies()
{
    return speciesName;
}

//===================================
// SIZE. Doodlebug
//===================================
Doodlebug::Doodlebug() : Organism(){};

Doodlebug::Doodlebug(int the_row, int the_col) : Organism(the_row, the_col){};

void Doodlebug::move(int direction)
{
    switch (direction)
    {
    case 1: // up
        row -= 1;
        break;
    case 2: // down
        row += 1;
        break;
    case 3: // left
        col -= 1;
        break;
    case 4:
        col += 1;
        break;
    }
    haveMoved = true;
}

void Doodlebug::breed()
{
    timeSurvived = 0;
}

void Doodlebug::starve() {}

string Doodlebug::getSpecies()
{
    return speciesName;
}

void Doodlebug::incrementTimeNotEat()
{
    timeNotEat += 1;
}

void Doodlebug::resetTimeNotEat()
{
    timeNotEat = 0;
}

int Doodlebug::getTimeNotEat()
{
    return timeNotEat;
}