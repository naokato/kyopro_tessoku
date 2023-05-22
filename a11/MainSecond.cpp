#include <iostream>
#include <algorithm>
using namespace std;

int N, X, A[100009];

int main() {
  cin >> N >> X;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // int L = 1;
  // int R = N;

  // while (L < R) {
  //   int M = (L + R) / 2;
  //   if (A[M] < X) L = M + 1;
  //   else R = M;
  // }
  // cout << L << endl;

  int pos = lower_bound(A + 1, A + N + 1, X) - A;
  if (pos <= N && A[pos] == X) cout << pos << endl;
  else cout << -1 << endl;

  return 0;
}
