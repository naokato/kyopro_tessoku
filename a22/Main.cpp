#define DEBUG 0
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100009], B[100009];
int dp[100009];

int main() {
  // input
  cin >> N;
  for (int i = 1; i < N; i++) cin >> A[i];
  for (int i = 1; i < N; i++) cin >> B[i];

  dp[1] = 0;
  // if there is no route to i, then it cannot be used as enable path
  for (int i = 2; i <= N; i++) dp[i] = -100000000;
  for (int i = 1; i < N; i++) {
    dp[A[i]] = max(dp[A[i]], dp[i] + 100);    
    dp[B[i]] = max(dp[B[i]], dp[i] + 150);    
  }

  #if DEBUG
  for (int i = 1; i <= N; i++) cout << dp[i] << " ";
  cout << endl;
  #endif

  cout << dp[N] << endl;
  return 0;
}
