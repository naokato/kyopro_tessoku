#include <iostream>
#include <algorithm>
using namespace std;

int N, K, A[100009];
int R[100009];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  R[0] = 1;
  for (int i = 1; i <= N - 1; i++) {
    int pos = lower_bound(A + 1, A + N + 1, K + A[i]) - A;
    if (pos <= N && A[pos] == K + A[i])  R[i] = pos;
    else R[i] = pos - 1;

    // R[i] = R[i - 1];
    // while (A[R[i] + 1] - A[i] <= K && R[i] < N) {
    //   R[i]++;
    // }
  }

  long long Answer = 0;
  for (int i = 1; i <= N - 1; i++) {
    Answer += R[i] - i;
  }

  cout << Answer << endl;
}
