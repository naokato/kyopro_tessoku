#include <iostream>
using namespace std;

int N, A[2009];
int dp[2009][2009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // initialize dp
  for (int i = 1; i <= N; i++) dp[N][i] = A[i];

  // dynamic programming
  for (int i = N - 1; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
      if (i % 2 == 1) {
        // Taro
        if (dp[i + 1][j] >= dp[i + 1][j + 1]) dp[i][j] = dp[i + 1][j];
        else dp[i][j] = dp[i + 1][j + 1];
      } else {
        // Jiro
        if (dp[i + 1][j] >= dp[i + 1][j + 1]) dp[i][j] = dp[i + 1][j + 1];
        else dp[i][j] = dp[i + 1][j];
      }
    }
  }

  cout << dp[1][1] << endl;
  return 0;
}
