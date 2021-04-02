#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "enter n"<<endl;
    cin >> n;

    int spaceLimit = n - 1;
    int starLimit = n - spaceLimit;
    for (int i = 0; i < 2 * n + 1; ++i) {
        for (int j = 0; j <= spaceLimit; ++j) {
            cout << ".";
        }
        for (int j = 1; j < starLimit; ++j) {
            cout << "* ";
        }
        cout << endl;
        if (i < n) {
            spaceLimit--; starLimit++;
        }
        else{
            spaceLimit++; starLimit--;
        }
    }

    return 0;
}