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
    int left = lower_bound(X, X + N + 2, X[i] - R) - X;
    int right = lower_bound(X, X + N + 2, X[i] - L + 1) - X; right--; 
    dp[i] %= mod;

    if (right == -1) dp[i] = 0;
    else dp[i] = sum[right];
    if (left >= 1) dp[i] -= sum[left - 1];
    dp[i] = (dp[i] + mod) % mod;

    sum[i] = sum[i - 1] + dp[i];
    sum[i] %= mod;
  }

  cout << dp[N + 1] << endl;
}
