/*
Author: Sherly Hartono

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

vector<int> findMinMax(vector<int> the_vector)
{
    vector<int> minMaxVector; 

    // 1. base case 1: if there is one item
    if(the_vector.size() == 1)
    {
        // insert min
        minMaxVector.push_back(the_vector[0]);
        // insert max
        minMaxVector.push_back(the_vector[0]);

        return minMaxVector;
    }

    // 2. base case 2: if there are two items
    if(the_vector.size() == 2)
    {
        //compare
        if(the_vector[0] < the_vector[1])
        {
            //low is min
            minMaxVector.push_back(the_vector[0]);
            minMaxVector.push_back(the_vector[1]);
        }
        else
        {
            //hi is min
            minMaxVector.push_back(the_vector[0]);
            minMaxVector.push_back(the_vector[1]);
        }

        return minMaxVector;
    }

    // 3. 3rd case: f there are more than 2 items
    // get middle index
    int mid = the_vector.size() /2;
    // cout << "mid index is" << mid <<endl;

    // create left vector and right vector 
    vector<int> vectorLeft, vectorRight;

    // insert element to vector left
    for(int i = 0; i <= mid; i++)
    {
        vectorLeft.push_back(the_vector[i]);
    }

    // insert element to vector right
    for(int i = mid+1; i < the_vector.size(); i++)
    {
        vectorRight.push_back(the_vector[i]);
    }

    // get the min max of these two vector
    vector <int> minMaxLeftVector = findMinMax(vectorLeft);
    vector <int> minMaxRightVector = findMinMax(vectorRight);


    // 1. Get the minimum from left and right vector
    if(minMaxLeftVector[0] < minMaxRightVector[0])
    {
        // left is min
        minMaxVector.push_back(minMaxLeftVector[0]);
    }
    else
    {
        // right is min
        minMaxVector.push_back(minMaxRightVector[0]);
    }

    // 2. Get the maximum from left and right vector
    if(minMaxLeftVector[1] > minMaxRightVector[1])
    {
        // left is max
        minMaxVector.push_back(minMaxLeftVector[1]);
    }
    else
    {
        // right is max
        minMaxVector.push_back(minMaxRightVector[1]);
    }

    return minMaxVector;

}

int main()
{
    vector<int> vectInt{1343, 11, 445, 2, 330, 73243, 123};

    // cout << vectInt.size() <<endl;
    vector<int> minMax = findMinMax(vectInt);

    for (int x : minMax)
    {
        cout << x << " ";

    }
}