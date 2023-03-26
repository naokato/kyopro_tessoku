#include <iostream>
using namespace std;

int N, A[200009];
int C[109];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  for (int i = 1; i <= N; i++) {
    C[A[i] % 100]++;
  }

  long long answer = 0;
  for (int i = 1; i <= 49; i++) {
    answer += C[i] * C[100 - i];
  }
  answer += (C[0] * (C[0] - 1)) / 2;
  answer += (C[50] * (C[50] - 1)) / 2;
  cout << answer << endl;
  return 0;
}
