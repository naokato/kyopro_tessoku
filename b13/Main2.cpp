#include <iostream>
using namespace std;

int N, K, A[100009];
long long CS[100009];
// R[i] is max number such that A[i] + ... + A[R[i]] <= K
int R[100009];

int main() {
  // input
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // cumlative sum
  CS[0] = 0;
  for (int i = 1; i <= N; i++) CS[i] += CS[i - 1] + A[i];
  // check
  for (int i = 1; i <= N; i++) cout << CS[i] << " ";
  cout << endl;

  // two pointer technique
  for (int i = 1; i <= N; i++) {
    if (i == 1) {
      R[i] = 0;
    } else {
      R[i] = R[i - 1];
    }

    while(R[i] < N && CS[R[i] + 1] - CS[i - 1] <= K) {
      R[i] += 1;
    }
  }

  long long Answer = 0;
  for (int i = 1; i <= N; i++) {
    Answer += R[i] - (i - 1);
  }
  cout << Answer << endl;
  return 0;
}
