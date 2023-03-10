#include <iostream>
using namespace std;

int N;
int F[10000009];
const int mod = 1000000007;

int main() {
  cin >> N;

  F[1] = 1;
  F[2] = 1;
  for (int i = 3; i <= N; i++) {
    F[i] = F[i - 2] + F[i - 1];
    // 和の一部のあまりを先に求めても、最終的な計算結果は変わらない
    F[i] %= mod;
  }

  cout << F[N] << endl;
  return 0;
}
