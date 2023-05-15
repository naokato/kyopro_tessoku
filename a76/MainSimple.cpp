#include <iostream>
#include <algorithm>
using namespace std;

const long long mod =  1000000007;
int N, W, L, R, X[150009];

long long dp[150009];
long long sum[150009];

int main() {
  cin >> N >> W >> L >> R;
  for (int i = 1; i <= N; i++) cin >> X[i];

  X[0] = 0;
  X[N + 1] = W;
  
  dp[0] = 1;
  sum[0] = dp[0];

  for (int i = 1; i <= N + 1; i++) {
    for (int j = 0; j < i; j++) {
      // int left = lower_bound(X, X + i + 1);
      if (X[i] - X[j] >= L && X[i] - X[j] <= R) dp[i] += dp[j];
      dp[i] %= mod;
    }
  }

  cout << dp[N + 1] << endl;
}
