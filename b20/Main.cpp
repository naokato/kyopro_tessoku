#define DEBUG 0
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
int sizeS, sizeT;
int dp[2009][2009];

int main() {
  // input
  cin >> S >> T;
  sizeS = S.size();
  sizeT = T.size();

  dp[0][0] = 0;
  // j 個追加すれば一致
  for(int j = 1; j <= sizeT; j++) dp[0][j] = j;
  // i 個削除すれば一致
  for(int i = 1; i <= sizeS; i++) dp[i][0] = i;

  for(int i = 1; i <= sizeS; i++) {
    for(int j = 1; j <= sizeT; j++) {
      if (S[i - 1] == T[j - 1]) {
        // use initializer_list as a argument
        dp[i][j] = min({ dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] });
      } else {
        dp[i][j] = min({ dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1 });
      }
    }
  }


  #if DEBUG
  cout << "    ";
  for(int j = 0; j <= sizeT; j++) {
    cout << T[j] << " ";
  }
  cout << endl;
  for(int i = 0; i <= sizeS; i++) {
    if (i == 0) cout << "  ";
    else cout << S[i - 1] << " ";
    for(int j = 0; j <= sizeT; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  #endif

  // answer
  cout << dp[sizeS][sizeT] << endl;
  return 0;
}
