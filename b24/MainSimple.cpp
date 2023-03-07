#define DEBUG 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, X[100009], Y[100009];
// (ソート済の) i番目までの最長の箱数
int dp[100009];
int L[100009];

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

  vector<pair<int, int>> vec;
  for (int i = 1; i <= N; i++) vec.push_back({X[i], Y[i]});

  sort(vec.begin(), vec.end());
  
  #if DEBUG
  for (const auto& item: vec) {
    cout << item.first << " " << item.second << endl;
  }
  #endif

  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    const auto& itemAtI = vec[i - 1];
    // 最低限自分自身
    dp[i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      const auto& itemAtJ = vec[j - 1];
      
      if (itemAtJ.second < itemAtI.second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  #if DEBUG
  for (int i = 1; i <= N; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
  #endif

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    answer = max(answer, dp[i]);
  }
  cout << answer << endl;
}
