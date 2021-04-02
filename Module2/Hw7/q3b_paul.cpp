#include <iostream>
using namespace std;
int main() {
  int a[] =  {27, 26, 25, 10,  2, 1};
  int p = 2;
  int i = 0;
  int j = sizeof(a) / sizeof(*a) - 1;
  while (i < j) {
    while (i < j && a[i] < p) {
      ++i;
    }
    while (i < j && a[j] >= p) {
      --j;
    }
    if (i < j) {
      std::cout << "swap" << endl;
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  for (int &it : a) {
    std::cout << ' ' << it;
  }
  return 0;
}