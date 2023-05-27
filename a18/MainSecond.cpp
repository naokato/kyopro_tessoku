#include <iostream>
using namespace std;

int N, S, A[69];
bool dp[69][10009];

int main() {
  cin >> N >> S;
  for (int i = 1; i <= N; i++) cin >> A[i];
  
  dp[0][0] = true;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= S; j++) {
      dp[i][j] = dp[i - 1][j] || (j >= A[i] && dp[i - 1][j - A[i]]);
    }
  }

  if (dp[N][S]) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
  

//  bool Answer = false;
//  for (long long i = 0; i < (1 << N); i++) {
//    int sum = 0;
//
//    for (int j = 0; j < N; j++) {
//      long long wari = (1 << j);
//      if ((i / wari) % 2 == 1) sum += A[j + 1];
//    }
//    if (sum == S) Answer = true; 
//  }
//
//  if (Answer) cout << "Yes" << endl;
//  else cout << "No" << endl;
