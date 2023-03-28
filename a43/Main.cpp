#include <iostream>
#include <algorithm>
using namespace std;

int N, L, A[200009];
char B[200009];

int main() {
  cin >> N >> L;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    if (B[i] == 'E') answer = max(answer, L - A[i]);
    else answer = max(answer, A[i]);
  }

  cout << answer << endl;
  return 0;
}
