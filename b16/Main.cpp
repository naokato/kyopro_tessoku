#include <iostream>
#include <cmath>
using namespace std;

int N;
int H[100009];
long long DP[100009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> H[i];

  DP[1] = 0;
  DP[2] = abs(H[1] - H[2]);
  for (int i = 3; i <= N; i++) {
    DP[i] =  min(
      DP[i - 2] + abs(H[i] - H[i - 2]),
      DP[i - 1] + abs(H[i] - H[i - 1])
    );
  }
  cout << DP[N] << endl;
  return 0;
}
