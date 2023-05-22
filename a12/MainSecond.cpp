#include <iostream>
using namespace std;

int N, K, A[100009];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  long long L = 1;
  long long R = 1'000'000'000;

  while (L < R) {
    long long M = (L + R) / 2;
    long long Current = 0;
    for (int i = 1; i <= N; i++) {
      Current += M / A[i];
    }
    if (K > Current) L = M + 1;
    else R = M;
  }

  cout << L << endl;
  return 0;
}
