#define DEBUG 0
#include <iostream>
using namespace std;

long long a, b;
long long A[39];
long long mod = 1000000007;

int main() {
  cin >> a >> b;

  // b <= 10^9 < 2^30 より、30回のループで十分
  A[1] = a;
  for (int i = 2; i <= 30; i++) {
    A[i] = (A[i - 1] * A[i - 1]) % mod ;
  }
  
  #if DEBUG
  for (int i = 1; i <= 30; i++) {
    cout << A[i] << endl;
  }
  cout << endl;
  #endif

  long long answer = 1;
  for (int i = 1; i <= 30; i++) {
    long long wari = 1 << (i - 1);
    if ((b / wari) % 2 == 1) {
      answer = (answer * A[i]) % mod; 
    }
  }

  cout << answer << endl;
  return 0;
}
