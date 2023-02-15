#include <iostream>
using namespace std;

int main() {
  int N, A[100009];
  int Q, L[100009], R[100009];

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  cin >> Q;
  for (int j = 1; j <= Q; j++) cin >> L[j] >> R[j];

  int cumulativeSum[100009];
  cumulativeSum[0] = 0;
  for (int i = 1; i <= N; i++) cumulativeSum[i] = cumulativeSum[i - 1] + A[i];
  
  // check cumulativeSum
  // for (int i = 1; i <= N; i++) cout << cumulativeSum[i] << endl;

  for (int j = 1; j <= Q; j++) {
    int nankai = R[j] - L[j] + 1;
    int atari = cumulativeSum[R[j]] - cumulativeSum[L[j] - 1];
    if (nankai < 2 * atari) cout << "win" << endl;
    else if (nankai == 2 * atari) cout << "draw" << endl;
    else cout << "lose" << endl;
  }
  return 0;
}
