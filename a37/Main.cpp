#include <iostream>
using namespace std;

long long N, M, B, A[200009], C[200009];

int main() {
  cin >> N >> M >> B;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= M; i++) cin >> C[i];


  // answer = M * (A1 + ... + An) + M * N * B + N * (C1 + ... + Cm);
  long long sumOfAs = 0;
  for (int i = 1; i <= N; i++) sumOfAs += A[i];
  long long sumOfCs = 0;
  for (int i = 1; i <= M; i++) sumOfCs += C[i];
  long long answer = M * sumOfAs + M * N * B + N * sumOfCs;

  cout << answer << endl;
  return 0;
}
