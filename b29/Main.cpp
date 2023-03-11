#define DEBUG 0
#include <iostream>
using namespace std;

long long Power(long long a, long long b, long long mod) {
  long long p = a;
  long long answer = 1; 

  // b <= 10^18 = (10^3)^6 < (2^10)^6 = 2^60 より、60回で十分
  for (int i = 0; i < 60; i++) {
    long long wari = 1LL << i;
    #if DEBUG
    cout << "wari=" << wari << endl;
    cout << "i=" << i <<":"<< (b / wari) % 2 << endl;
    #endif
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
