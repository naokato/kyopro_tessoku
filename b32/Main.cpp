#include <iostream>
using namespace std;

int N, K, A[109];
bool dp[100009];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= K; i++) cin >> A[i];
  
  for (int i = 1; i <= N; i++) {
    dp[i] = false;
    for (int j = 1; j <= K; j++) {
      if (i >= A[j] && dp[i - A[j]] == false) dp[i] = true;
    }
  }

  if (dp[N]) cout << "First" << endl;
  else cout << "Second" << endl;
  return 0;
}
