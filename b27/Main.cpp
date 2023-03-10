#include <iostream>
using namespace std;

long long A, B;

int gcd(int a, int b) {
  int r = a % b;
  if (r == 0) return b;
  else return gcd(b, r);
} 

int main() {
  cin >> A >> B;
  long long answer = (A * B) / gcd(A, B);
  
  cout << answer << endl;
  return 0;
}
