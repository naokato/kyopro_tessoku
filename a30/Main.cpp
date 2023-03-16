#define DEBUG 0
#include <iostream>
using namespace std;

long long factorialWithMod(long long num, long long mod) {
  long long result = 1;
  for (int i = 1; i <= num; i++) {
    result = (result * i) % mod;
  }
  return result;
}

long long kurikaeshi2jo(long long num, long long p, long long mod) {
  long long answer = 1;
  long long r = num;
  for (int i = 0; i < 30; i++) {
    long long wari = 1LL << i;
    if ((p / wari) % 2 == 1) answer = (answer * r) % mod;
    r = (r * r) % mod;
  }
  return answer;
}

int main() {
  const long long M = 1000000007LL;

  int n, r;
  cin >> n >> r;

  // 分子
  long long numerator = factorialWithMod(n, M);
  #if DEBUG
  cout << numerator << endl;
  #endif

  // 分母
  long long denominator = (factorialWithMod(r, M) * factorialWithMod(n - r, M)) % M;
  #if DEBUG
  cout << denominator << endl;
  #endif

  // calculate denominator ^ (M - 2)
  long long kake = kurikaeshi2jo(denominator, M - 2, M);

  long long result = (numerator * kake) % M;
  cout << result << endl;
  return 0;
}
