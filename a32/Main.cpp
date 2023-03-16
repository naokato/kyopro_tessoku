#include <iostream>
using namespace std;

int N, A, B;
bool dp[100009];

int main() {
  cin >> N >> A >> B;

  for (int i = 1; i < A; i++) dp[i] = false;

  for (int i = A; i <= N; i++) {
    if (dp[i - A] == false) dp[i] = true;
    else if (i >= B && dp[i - B] == false) dp[i] = true;
    else dp[i] = false;
  }

  if(dp[N]) cout << "First" << endl;
  else cout << "Second" << endl;

  return 0;
}
