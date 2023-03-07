#define DEBUG 0
#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009];
// for each i, dp[i] mean the length of the longest increasing subsequences
// which has the last element A[i]
int dp[100009];
int L[100009];

void printL() {
  #if DEBUG
  for (int i = 1; i <= N; i++) {
    cout << L[i] << " ";
  }
  cout << endl;
  #endif
}

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // dynamic programing
  int LEN = 0;
  for (int i = 1; i <= N; i++) {
    int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
    dp[i] = pos;
    L[dp[i]] = A[i];
    if (dp[i] > LEN) LEN++;
    printL();
  }
  
  #if DEBUG
  for (int i = 1; i <= N; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
  #endif

  cout << LEN << endl;
  return 0;
}
