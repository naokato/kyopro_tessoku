#define DEBUG 0
#include <iostream>
using namespace std;

int N, S;
int A[69];
bool dp[69][10009];

int main() {
  cin >> N >> S;
  for (int i = 1; i <= N; i++) cin >> A[i];

  dp[0][0] = true;
  for (int j = 1; j <= S; j++) dp[0][j] = false;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i][j] = dp[i - 1][j] || (j >= A[i] && dp[i - 1][j - A[i]]);
    }
  }
  
  #if DEBUG
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= S; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  #endif

  if (dp[N][S]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
