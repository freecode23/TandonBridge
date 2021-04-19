/*
Author: Sherly Hartono
Hw 14

(Weiss 7.40): The following divide-and-conquer algorithm is proposed for finding the simultaneous
maximum and minimum: If there is one item, it is the maximum and
minimum, and if there are two items, then compare them, and in one comparison
you can find the maximum and minimum. Otherwise, split the input into two
halves, divided as evenly as possibly (if N is odd, one of the two halves will have
one more element than the other). Recursively find the maximum and minimum
of each half, and then in two additional comparisons produce the maximum and
minimum for the entire problem.

Write the above function which will take in a vector and solve the problem,
producing a vector of two elements, the min and max.
*/

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int MIN_INDEX = 0;
const int MAX_INDEX = 1;
vector<int> findMinMax(const vector<int> the_vector, int lo, int hi);

int main()
{
    vector<int> vectInt{1343, 11 ,2, 299, 122 ,33, 712321,712321};
    vector<int> minMax = findMinMax(vectInt, 0, vectInt.size()-1);

    cout << "min is: " << minMax[MIN_INDEX] <<endl;
    cout << "max is: " << minMax[MAX_INDEX] <<endl;
}

vector<int> findMinMax(const vector<int> the_vector, int lo, int hi)
{
    vector<int> minMaxVector; 

    // 1. Base case 1: if there is one item
    if(lo == hi)
    {
        // insert min
        minMaxVector.push_back(the_vector[lo]);
        // insert max
        minMaxVector.push_back(the_vector[hi]);

        return minMaxVector;
    }

    // 2. Base case 2: if there are two items
    if(lo+1 == hi)
    {
        //compare
        if(the_vector[lo] < the_vector[hi])
        {
            //low is min
            minMaxVector.push_back(the_vector[lo]);
            minMaxVector.push_back(the_vector[hi]);
        }
        else
        {
            //hi is min
            minMaxVector.push_back(the_vector[hi]);
            minMaxVector.push_back(the_vector[lo]);
        }

        return minMaxVector;
    }

    // 3. Recursive case: if there are more than 2 items
    // get middle index
    int mid = (lo + hi) /2;

    // find min and max from the split vector
    vector <int> minMaxLeftVector = findMinMax(the_vector, lo, mid);
    vector <int> minMaxRightVector = findMinMax(the_vector, mid+1, hi);

    // 1. Compare Minimum
    if(minMaxLeftVector[MIN_INDEX] < minMaxRightVector[MIN_INDEX])
    {
        // left is min
        minMaxVector.push_back(minMaxLeftVector[MIN_INDEX]);
    }
    else
    {
        // right is min
        minMaxVector.push_back(minMaxRightVector[MIN_INDEX]);
    }

    // 2. Compare Maximum
    if(minMaxLeftVector[MAX_INDEX] > minMaxRightVector[MAX_INDEX])
    {
        // left is max
        minMaxVector.push_back(minMaxLeftVector[MAX_INDEX]);
    }
    else
    {
        // right is max
        minMaxVector.push_back(minMaxRightVector[MAX_INDEX]);
    }

    return minMaxVector;

}