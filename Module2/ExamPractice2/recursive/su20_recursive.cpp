/*
Question 5
For example, if bitsArr = [1, 0, 0, 1, 1, 0].
the call bitsArrToInt(bitsArr, 6) should return 38.
it should return the positive integer that is represented in bitsArr.
*/

/*
void convertToBinary(unsigned int n)
{
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
    printf("%d", n % 2);
}
*/


#include <iostream>
#include <math.h>
using namespace std;
int bitsArrToInt(int *bitsArr, int bitsArrSize);

int main()
{
    const int bitsArrSize = 6;
    int bitsArr[bitsArrSize] = {1, 0, 0, 1, 1, 0};
    cout << bitsArrToInt(bitsArr, bitsArrSize);
}

int bitsArrToInt(int *bitsArr, int bitsArrSize)
{
    // base case
    // case 1, the bit is 1
    if ((bitsArrSize == 1) && (bitsArr[0] == 1))
    {
        return pow(2, bitsArrSize - 1);
    }
        // case 2, the bit is 0
    else if ((bitsArrSize == 1) && (bitsArr[0] == 0))
    {
        return 0;
    }

    // recursive from front
    if (bitsArr[0] == 1)
    {
        return pow(2, bitsArrSize - 1) +
               bitsArrToInt(bitsArr + 1, bitsArrSize - 1);
    }
    else
    {
        return (0 + bitsArrToInt(bitsArr + 1, bitsArrSize - 1));
    }
}