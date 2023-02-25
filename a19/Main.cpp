#define DEBUG 0
#include <iostream>
#include <algorithm>
using namespace std;

int N, W;
int w[109], v[109];
long long dp[109][100009];
long long batsu = -100'000'000'000'000LL;

int main() {
  // input
  cin >> N >> W;
  for(int i = 1; i <= N; i++) cin >> w[i] >> v[i];

  // dp
  dp[0][0] = 0;
  for(int j = 1; j <= W; j++) dp[0][j] = batsu;

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= W; j++) {
      if (j >= w[i]) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  #if DEBUG
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= W; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  #endif

  // answer
  long long answer = 0;
  for(int j = 0; j <= W; j++) {
    answer = max(answer, dp[N][j]);
  }
  cout << answer << endl;
  return 0;
}
