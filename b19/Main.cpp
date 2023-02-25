#define DEBUG 0
#include <iostream>
using namespace std;

int N, W;
int w[109],v[109];
long long dp[109][100009]; // i 番目まで選べる時、価値が j に出来た時の最小の重さ
int MAX_VALUE = 100000;
long long batsu = 1'000'000'000'000'000LL;

int main() {
  cin >> N >> W;
  for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

  // initialize by big weight
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= MAX_VALUE; j++) {
      dp[i][j] = batsu;
    }
  }
  dp[0][0] = 0;

  
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= MAX_VALUE; j++) {
      if (j >= v[i]) {
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  #if DEBUG
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= MAX_VALUE; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  #endif

  // answer
  long long answer = 0;
  for (int j = 0; j <= MAX_VALUE; j++) {
    if (dp[N][j] <= W) answer = j;
  }
  cout << answer << endl;
  return 0;
}
