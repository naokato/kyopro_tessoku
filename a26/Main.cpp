#include <iostream>
#include <cmath>
using namespace std;

int Q, X[300009];

int main() {
  cin >> Q;
  for (int i = 1; i <= Q; i++) cin >> X[i];

  for (int i = 1; i <= Q; i++) {
    int squareRoot = (int) sqrt(X[i]);
    int isPrime = true;
    for (int j = 2; j <= squareRoot; j++) {
      if (X[i] % j == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
