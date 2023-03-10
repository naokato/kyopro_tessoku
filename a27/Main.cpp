#include <iostream>
using namespace std;

int A, B;

int gcd(int a, int b) {
  int r = a % b;
  if (r == 0) return b;
  else return gcd(b, r);
}

int main() {
  cin >> A >> B;

  cout << gcd(A, B) << endl;

  return 0;
}
