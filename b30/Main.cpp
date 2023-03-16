#include <iostream>
using namespace std;

long long H, W;

long long kurikaeshi2jo(long long a, long long b, long long mod) {
  long long answer = 1;
  long long p = a;
  for (int i = 0; i < 30; i++) {
    long long wari = (1 << i) % mod;
    if ((b / wari) % 2 == 1) answer = (answer * p) % mod;
    p = (p * p) % mod;
  }
  return answer;
}

int main() {
  const long long mod = 1000000007LL;
  cin >> H >> W;

  int n = H + W - 2;
  int r = W - 1;

  // calculate (H + W - 2) C (W -1)
  long long numerator = 1;
  for (int i = 1; i <= n; i++) numerator = (numerator * i) % mod;
  long long denominator = 1;
  for (int i = 1; i <= r; i++) denominator = (denominator * i) % mod;
  for (int i = 1; i <= n - r; i++) denominator = (denominator * i) % mod;

  long long result = (numerator * kurikaeshi2jo(denominator, mod - 2, mod)) % mod;
  cout << result << endl;
  return 0;
}
