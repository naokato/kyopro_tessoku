#include <iostream>
using namespace std;

int N;
long long K;
long long A[100009];

bool isAnswerIn(long long m) {
  long long sum = 0;
  for (int i = 1; i <= N; i++) {
    sum += m / A[i];
  }
  if (sum >= K) return true;
  else return false;
}

int main() {
  // input
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // binary search related to the time
  long long L = 1;
  long long R = 1'000'000'000;
  while (L < R) {
    long long M = (L + R) / 2;
    bool result = isAnswerIn(M);
    if (result) R = M;
    else L = M + 1;
  }
  cout << L << endl;
  return 0;
}
