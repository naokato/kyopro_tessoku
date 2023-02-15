#include <iostream>
using namespace std;

int T, Sabun[500009], Answer[500009];
int N, L[500009], R[500009];

int main() {
  // input
  cin >> T >> N;
  for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

  // calculate sabun
  for (int i = 1; i <= N; i++) {
    Sabun[L[i]] += 1;
    Sabun[R[i]] -= 1;
  }

  // check sabun
  // for (int i = 0; i <= T; i++) cout << Sabun[i] << " ";
  // cout << endl;

  // calculate staff count
  Answer[0] = Sabun[0];
  cout << Answer[0] << endl;
  for (int i = 1; i < T; i++) {
    Answer[i] = Answer[i - 1] + Sabun[i];
    cout << Answer[i] << endl;
  }
  return 0;
}
