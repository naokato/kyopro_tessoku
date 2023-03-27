#include <iostream>
using namespace std;

int N, K, A[309], B[309];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

  int answer = 0;
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      int candidateCount = 0;
      for (int k = 1; k <= N; k++) {
        if (i <= A[k] && A[k] <= i + K && j <= B[k] && B[k] <= j + K) candidateCount++;
      }
      answer = max(answer, candidateCount);
    }
  }

  cout << answer << endl;
  return 0;
}
