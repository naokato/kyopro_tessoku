#include <iostream>
using namespace std;

int N, K, A[100009];
// for each i, R[i] = t such as A[t] <= A[i] + K
int R[100009];

int main() {
  // input
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // calculate R[i] by lower_bound
  for (int i = 1; i <= N - 1; i++) {
    int lb = lower_bound(A + i + 1, A + N + 1, A[i] + K) - A;
    if (lb == N + 1) R[i] = N;
    else if (A[i] + K == A[lb]) R[i] = lb;
    else R[i] = lb - 1;
    // cout << R[i] << endl;
  }
  // cout << endl;

  long long answer = 0;
  for (int i = 1; i <= N - 1; i++) {
    answer += R[i] - i;
  }
  cout << answer << endl;
  return 0;
}
