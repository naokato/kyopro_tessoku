#include <iostream>
using namespace std;

int main() {
  int A[4];
  A[1] = 1;
  A[2] = 2;
  A[3] = 3;

  int lb = lower_bound(A + 2, A + 4, 0) - A;
  cout << lb << endl;
}
