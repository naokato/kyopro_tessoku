#include <iostream>
using namespace std;

int N, A[100009];
// for each i, dp[i] mean the length of the longest increasing subsequences
// which has the last element A[i]
int dp[100009];

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // dynamic programing
  for (int i = 1; i <= N; i++) {
    dp[i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      if (A[i] > A[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    answer = max(answer, dp[i]); 
  }
  cout << answer << endl;
  return 0;
}
