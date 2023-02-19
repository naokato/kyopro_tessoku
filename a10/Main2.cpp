#include <iostream>
using namespace std;

int N, A[100009];
int D, L[100009], R[100009];
int P[100009];
int Q[100009];

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  cin >> D;
  for (int i = 1; i <= D; i++) cin >> L[i] >> R[i];

  // max for left side
  for (int i = 1; i <= N; i++) {
    P[i] = max(P[i - 1], A[i]);
  }
  
  // max for right side
  Q[N] = A[N];
  for (int i = N - 1; i >= 1; i--) {
    Q[i] = max(Q[i + 1], A[i]);
  }

  // check
  // for (int i = 1; i <= N; i++) {
  //   cout << P[i] << " ";
  // }
  // cout << endl;
  // for (int i = 1; i <= N; i++) {
  //   cout << Q[i] << " ";
  // }
  // cout << endl;

  // answer
  for (int i = 1; i <= D; i++ ) {
    cout << max(P[L[i] - 1], Q[R[i] + 1]) << endl;
  }
  return 0;
}
