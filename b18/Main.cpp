#define DEBUG 0
#include <iostream>
#include <vector>
#include <algorithm>
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

  if (!dp[N][S]) {
    cout << -1 << endl;
    return 0;
  }

  int j = S;
  vector<int> vec;
  for (int i = N; i >= 1; i--) {
    if (dp[i - 1][j]) {
      j = j;
    } else {
      vec.push_back(i);
      j = j - A[i];
    }

    // if ((j >= A[i] && dp[i - 1][j - A[i]])) {
    //   vec.push_back(i);
    //   j = j - A[i];
    // } else {
    //   j = j;
    // }
  }

  reverse(vec.begin(), vec.end());
  
  // answer
  cout << vec.size() << endl;
  for (int i = 0; i < vec.size(); i++) {
    if (i >= 1) cout << " ";
    cout << vec[i];
  }

  return 0;
}
