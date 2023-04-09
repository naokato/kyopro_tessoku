#define DEBUG 0
#include <iostream>
#include <cmath>
using namespace std;

int N, K;
int dp[32][300009];

int main() {
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    int total = 0;
    for (int j = 0; j <= 6; j++) {
      int wari = pow(10, j);
      int remainder = (i / wari) % 10;
      total += remainder;
    }
    dp[0][i] = i - total;
  }

  for (int i = 1; i <= 29; i++) {
    for (int j = 1; j <= N; j++) {
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }
  
  #if DEBUG
  for (int i = 0; i <= 29; i++) {
    for (int j = 1; j <= N; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  #endif

  for (int j = 1; j <= N; j++) {
    int current = j;
    for (int i = 29; i >= 0; i--) {
      int wari = (1 << i);
      if ((K / wari) % 2 == 1) current = dp[i][current];
    }
    cout << current << endl;
  }

  return 0;
}
