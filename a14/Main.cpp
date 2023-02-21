#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[1009], B[1009], C[1009], D[1009];
int P[1000009], Q[1000009];

int main() {
  // input
  cin >> N >> K;
  for (int i = 1; i<= N; i++) cin >> A[i];
  for (int i = 1; i<= N; i++) cin >> B[i];
  for (int i = 1; i<= N; i++) cin >> C[i];
  for (int i = 1; i<= N; i++) cin >> D[i];

  // calculate A + B. C + D
  for (int i = 1; i<= N; i++) {
    for (int j = 1; j<= N; j++) {
      P[(i - 1) * N + j] = A[i] + B[j];
      Q[(i - 1) * N + j] = C[i] + D[j];
    }
  }
  
  // check
  // for (int i = 1; i<= N * N; i++) {
  //     cout << P[i] << " ";
  // }
  // cout << endl;
  // for (int i = 1; i<= N * N; i++) {
  //     cout << Q[i] << " ";
  // }
  // cout << endl;

  // sort Q
  sort(Q + 1, Q + N * N + 1);

  // check sorted Q
  // for (int i = 1; i<= N * N; i++) {
  //     cout << Q[i] << " ";
  // }
  // cout << endl;

  // for each i, check j exists such that Q[j] = K - P[i]
  bool Answer = false;
  for (int i = 1; i<= N * N; i++) {
    int index = lower_bound(Q + 1, Q + N * N + 1, K - P[i]) - Q;
    if (index <= N * N && P[i] + Q[index] == K) {
      Answer = true;
      // cout << P[i] << " " << Q[index] << endl;
      break;
    }
  }
  if (Answer) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
