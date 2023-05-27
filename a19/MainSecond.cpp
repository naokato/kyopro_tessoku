#include <iostream>
#include <algorithm>
using namespace std;

int N, W, w[109], v[109];
long long dp[109][100009];

int main() {
  cin >> N >> W;
  for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= W; j++) {
      if (j >= w[i]) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  long long Answer = 0;
  for (int j = 1; j <= W; j++) {
    Answer = max(Answer, dp[N][j]);
  }
  cout << Answer << endl;
}
