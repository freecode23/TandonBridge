/*Source code of the above program is given below*/

/*NOTE: If you want in a different way, please let me know through comments; I will surely revert back to you.*/

#include <iostream>

using namespace std;

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize)

{

    outPosArrSize = 0;

    //counting the number of +ve numbers

    for (int i = 0; i < arrSize; i++)

    {

        if (arr[i] > 0)

            outPosArrSize++;
    }

    //allocate array dynamically

    int *outArr = new int[outPosArrSize];

    int j = 0;

    //store the +ve numbers into the output array

    for (int i = 0; i < arrSize; i++)

    {

        if (arr[i] > 0)

        {

            outArr[j] = arr[i];

            j++;
        }
    }

    return outArr;
}

void getPosNums2(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize)

{

    outPosArrSize = 0;

    //counting the number of +ve numbers

    for (int i = 0; i < arrSize; i++)

    {

        if (arr[i] > 0)

            outPosArrSize++;
    }

    //allocate array dynamically

    outPosArr = new int[outPosArrSize];

    int j = 0;

    //store the +ve numbers into the output array

    for (int i = 0; i < arrSize; i++)

    {

        if (arr[i] > 0)

        {

            outPosArr[j] = arr[i];

            j++;
        }
    }
}

int *getPosNums3(int *arr, int arrSize, int *outPosArrSizePtr)

{

    (*outPosArrSizePtr) = 0;

    //counting the number of +ve numbers

    for (int i = 0; i < arrSize; i++)

    {

        if (arr[i] > 0)

            (*outPosArrSizePtr)++;
    }

    //allocate array dynamically

    int *outArr = new int[(*outPosArrSizePtr)];

    int j = 0;

    //store the +ve numbers into the output array

    for (int i = 0; i < arrSize; i++)

    {

        if (arr[i] > 0)

        {

            outArr[j] = arr[i];

            j++;
        }
    }

    return outArr;
}

void getPosNums4(int *arr, int arrSize, int **outPosArrPtr, int *outPosArrSizePtr)

{

    *outPosArrSizePtr = 0;

    //counting the number of +ve numbers

    for (int i = 0; i < arrSize; i++)

    {

        if (arr[i] > 0)

            (*outPosArrSizePtr)++;
    }

    //allocate array dynamically

    (*outPosArrPtr) = new int[(*outPosArrSizePtr)];

    int j = 0;

    //store the +ve numbers into the output array

    for (int i = 0; i < arrSize; i++)

    {

        if (arr[i] > 0)

        {

            (*outPosArrPtr)[j] = arr[i];

            j++;
        }
    }
}

//function to display array elements

void display(int *arr, int size)

{

    cout << "\nOutput Array : ";

    for (int i = 0; i < size; i++)

        cout << arr[i] << " ";

    cout << endl
         << endl;
}

int main()

{

    //declaring necessary variables

    int arr[] = {3, -1, -3, 0, 6, 4};

    int arrSize = 6;

    int outPosArrSize;

    int *outPosArr;

    cout << "Calling function #1 :";

    outPosArr = getPosNums1(arr, arrSize, outPosArrSize);

    display(outPosArr, outPosArrSize);

    cout << "Calling function #2 :";

    getPosNums2(arr, arrSize, outPosArr, outPosArrSize);

    display(outPosArr, outPosArrSize);

    cout << "Calling function #3 :";

    outPosArr = getPosNums3(arr, arrSize, &outPosArrSize);

    display(outPosArr, outPosArrSize);

    cout << "Calling function #4 :";

    getPosNums4(arr, arrSize, &outPosArr, &outPosArrSize);

    display(outPosArr, outPosArrSize);

    return 0;
}