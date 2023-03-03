#define DEBUG 0
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int N, X[19], Y[19];
// given passed town's set and current town, dp expresses minimum travel time
double dp[1 << 16][19];

void printDp() {
  #if DEBUG
  for (int i = 0; i < (1 << N) ; i++) {
    for (int j = 1; j <= N ; j++) cout << dp[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  #endif
}

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N ; i++) cin >> X[i] >> Y[i];
  
  // initialize
  for (int i = 0; i < (1 << N) ; i++) {
    for (int j = 1; j <= N ; j++) {
      dp[i][j] = 1'000'000'000;
    }
  }

  // we can assume that we start from town 1,
  // because the answer will be a circle,
  // and its length does not depend on the start town
  dp[0][1] = 0;
  printDp();

  for (int i = 0; i < (1 << N) ; i++) {
    for (int j = 1; j <= N ; j++) {
      if (dp[i][j] >= 1'000'000'000) continue;

      for (int k = 1; k <= N ; k++) {
        int kAsFlag = 1 << (k - 1);
        
        // town k was already visited
        if ((i & kAsFlag) != 0) continue;
      
        double dist = sqrt(1.0 * (X[j] - X[k]) * (X[j] - X[k]) + 1.0 * (Y[j] - Y[k]) * (Y[j] - Y[k]));
        dp[i | kAsFlag][k] = min(dp[i | kAsFlag][k], dp[i][j] + dist);
      }
    }
  }
  printDp();

  // answer
  printf("%.12lf\n", dp[(1 << N) - 1][1]);
  return 0;
}
