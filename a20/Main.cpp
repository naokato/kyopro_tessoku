#define DEBUG 0
#include <iostream>
#include <string>
using namespace std;

string S, T;
int sizeS, sizeT;
int dp[2009][2009];

int main() {
  cin >> S >> T;
  sizeS = S.size();
  sizeT = T.size();

  for (int i = 0; i <= sizeS; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= sizeT; j++) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= sizeS; i++) {
    for (int j = 1; j <= sizeT; j++) {
      #if DEBUG
      cout << S[i - 1] << ":" << T[j - 1] << endl;
      #endif
      if (S[i - 1] == T[j - 1]) {
        dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + 1);
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  #if DEBUG
  for (int i = 0; i <= sizeS; i++) {
    for (int j = 0; j <= sizeT; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  # endif

  cout << dp[sizeS][sizeT] << endl;

  return 0;
}
