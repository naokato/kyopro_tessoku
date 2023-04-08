#include <iostream>
using namespace std;

int N, Q, A[100009], X[100009], Y[100009];
// 現在 j にいる場合の、2^i 日目にいる場所
int dp[30][100009];

int main() {
  cin >> N >> Q;
  for (int i = 1; i <= N ; i++) cin >> A[i];
  for (int i = 1; i <= Q ; i++) cin >> X[i] >> Y[i];

  // dp の計算
  for (int i = 1; i <= N; i++) dp[0][i] = A[i];
  for (int i = 1; i <= 29; i++) {
    for (int j = 1; j <= N; j++) {
      dp[i][j] = dp [i - 1][dp[i - 1][j]];
    }
  }
  
  for (int i = 1; i <= Q; i++) {
    int current = X[i]; 
    for (int j = 29; j >= 0; j--) {
      int wari = (1 << j);
      if ((Y[i] / wari) % 2 == 1) current = dp[j][current];
    }
    cout << current << endl;
  }

  return 0;
}
