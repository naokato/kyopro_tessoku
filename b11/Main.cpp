#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009];
int Q, X[100009];

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  cin >> Q;
  for (int i = 1; i <= Q; i++) cin >> X[i];

  // sort
  sort(A + 1, A + N + 1);
  // for (int i = 1; i <= N; i++) cout << A[i] << " ";
  // cout << endl;

  // lower_bound
  for (int q = 1; q <= Q; q++) {
    int Answer = lower_bound(A + 1, A + N + 1, X[q]) - A - 1;
    cout << Answer << endl;
  }
  return 0;
}
