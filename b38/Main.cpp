#include <iostream>
using namespace std;

int N;
char S[3009];
int I[3009];
int D[3009];

int main() {
  cin >> N;
  for (int i = 1; i <= N - 1; i++) cin >> S[i];

  I[1] = 1;
  for (int i = 1; i <= N - 1; i++) {
    if (S[i] == 'A') I[i + 1] = I[i] + 1;
    else I[i + 1] = 1;
  }

  D[N] = 1;
  for (int i = N; i >= 2; i--) {
    if (S[i - 1] == 'B') D[i - 1] = D[i] + 1;
    else D[i - 1] = 1;
  }

  int answer = 0;
  for (int i = 1; i <= N; i++) answer += max(I[i], D[i]);
  cout << answer << endl;
  return 0;
}
