#define DEBUG 1
#include <iostream>
using namespace std;

int N, M;
int A[109][19];
int dp[109][1030];
int T[109];

void printDp() {
  #if DEBUG
  for (int i = 0; i <= M; i++) {
    for (int j = 0; j < (1 << N) ; j++) cout << dp[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  #endif
}

int main() {
  // input
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) cin >> A[i][j];
  }

  // bit expression of A
  T[0] = 0;
  for (int i = 1; i <= M; i++) {
    T[i] = 0;
    for (int j = N; j >= 1; j--) {
      if (A[i][j] == 1) T[i] += (1 << (j - 1));
    }
  }

  #if DEBUG
  for (int i = 1; i <= M; i++) {
    cout << T[i] << " ";
  }
  cout << endl;
  #endif

  // initialize dp
  for (int i = 0; i <= M; i++) {
    dp[i][0] = 0;
    for (int j = 1; j < (1 << N) ; j++) dp[i][j] = 1000000000;
  }
  printDp();

  // dynamic programing
  for (int i = 1; i <= M; i++) {
    for (int j = 0; j < (1 << N) ; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      dp[i][j | T[i]] = min(dp[i][j | T[i]], dp[i - 1][j] + 1);
    }
  }
  printDp();

  // answer
  int answer = 1000000000;
  for (int i = 1; i <= M; i++) {
    answer = min(answer, dp[i][(1 << N) - 1]);
  }
  if (answer == 1000000000) cout << -1 << endl;
  else cout << answer << endl;
  return 0;
 
}
