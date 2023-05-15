#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int T[109], D[109];
vector<pair<int, int>> vec;
int dp[109][1449];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> T[i] >> D[i];
  for (int i = 1; i <= N; i++) vec.push_back(make_pair(D[i], T[i]));
  sort(vec.begin(), vec.end());
  
  for (int i = 1; i <= N; i++) {
    D[i] = vec[i - 1].first;
    T[i] = vec[i - 1].second;
  }

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) dp[i][j] = -1;

  dp[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= 1440; j++) {
      if (j < T[i] || j > D[i]) dp[i][j] = dp[i - 1][j];
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T[i]] + 1);
    }
  }
  
  int Answer = 0;
  for (int j = 1; j <= 1440; j++) {
    Answer = max(Answer, dp[N][j]);
  }

  cout << Answer << endl;
  return 0;
}
