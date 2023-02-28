#define DEBUG 1
#include <iostream>
using namespace std;

int N;
string S;
// S の左から l 番目から 右から r 番目までの、最長の回文の長さ
int dp[1009][1009];

int main() {
  cin >> N;
  cin >> S;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) dp[i][j] = 1;
      else dp[i][j] = 0;
    }
  }

  for (int LEN = 1; LEN <= N - 1; LEN++) {
    for (int l = 1; l <= N - LEN; l++) {
      int r = l + LEN;
      #if DEBUG
      cout << "---" << l << ":" << r << "---" << endl;
      cout << "S[l]=" << S[l - 1] << "/S[r]=" << S[r - 1] << endl; 
      #endif

      if (S[l - 1] != S[r - 1]) {
        dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]); 
      } else {
        dp[l][r] = dp[l + 1][r - 1] + 2;
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
  cout << dp[1][N] << endl;
  return 0;
}
