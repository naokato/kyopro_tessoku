#include <iostream>
#include <cmath>
using namespace std;

int N;

double f(double x) {
  return pow(x, 3) + x;
}

int main() {
  cin >> N;

  // x ^ 3 = N -x とすると、
  // x = (N - x) ^ (1/3) < N ^ (1/3) <= 100000 ^ (1/3) < 47
  double L = 1;
  double R = 47;
  while (L <= R) {
    // cout << L << ":" << R << endl; 
    double M = (L + R) / 2;
    double currentValue = f(M);
    double gosa = currentValue - N;
    if (abs(gosa) <= 0.001) {
      cout << M;
      return 0;
    }
    if (gosa >= 0) R = M;
    else L = M;
  }
  return 0;
}
