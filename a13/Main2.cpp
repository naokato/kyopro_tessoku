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
    if (i == 1) R[i] = 1;
    else R[i] = R[i - 1];
    while (R[i] < N && A[R[i] + 1] - A[i] <= K) {
      R[i] += 1;
    }
  }

  long long answer = 0;
  for (int i = 1; i <= N - 1; i++) {
    answer += R[i] - i;
  }
  cout << answer << endl;
  return 0;
}
