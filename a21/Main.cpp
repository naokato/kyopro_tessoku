#define DEBUG 0
#include <iostream>
#include <algorithm>
using namespace std;

int N, P[2009], A[2009];
int dp[2009][2009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> P[i] >> A[i];

  dp[1][N] = 0;
  for (int LEN = N - 2; LEN >= 0; LEN--) {
    // r = l + LEN <= N
    for (int l = 1; l <= N - LEN; l++) {
      int r = l + LEN;
      int score1 = 0;
      int score2 = 0;

      if (l <= P[l - 1] && P[l - 1] <= r) score1 = A[l - 1];
      if (l <= P[r + 1] && P[r + 1] <= r) score2 = A[r + 1];

      if (l == 1) {
        dp[l][r] = dp[l][r + 1] + score2;
      } else if (r == N) {
        dp[l][r] = dp[l - 1][r] + score1;
      } else {
        dp[l][r] = max(dp[l - 1][r] + score1, dp[l][r + 1] + score2);
      }
    }
  }

  #if DEBUG
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cout << dp[i][j] << " ";
    } 
    cout << endl;
  }
  #endif

  // answer
  int answer = 0;
  for (int i = 1; i <= N; i++) {
    answer = max(answer, dp[i][i]);
  }
  cout << answer << endl;
  return 0;
}
