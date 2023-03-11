#define DEBUG 0
#include <iostream>
using namespace std;

long long Power(long long a, long long b, long long mod) {
  long long p = a;
  long long answer = 1; 

  for (int i = 0; i < 30; i++) {
    int wari = 1 << i;
    if ((b / wari) % 2 == 1) {
      answer = (answer * p) % mod;
    }
    p = (p * p) % mod;
  }

  return answer;
}


int main() {
  long long a, b;
  long long mod = 1000000007;

  cin >> a >> b;
  cout << Power(a, b, mod) << endl;
  return 0;
}
