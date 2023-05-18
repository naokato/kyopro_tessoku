#include <iostream>
using namespace std;

int H, W, X[1509][1509], Q, A[100009], B[100009], C[100009], D[100009];
int sum[1509][1509];

int main() {
  // input
  cin >> H >> W;
  for (int i = 1; i <= H; i++)
    for (int j = 1; j <= W; j++) cin >> X[i][j];
  cin >> Q;
  for (int i = 1; i <= Q; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
  
  // initialize
  for (int i = 0; i <= H; i++) sum[i][0] = 0;
  for (int j = 0; j <= W; j++) sum[0][j] = 0;
  
  // calculate sum
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      sum[i][j] = sum[i][j - 1] + X[i][j];
    }
  }
  for (int j = 1; j <= W; j++) {
    for (int i = 1; i <= H; i++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j];
    }
  }
  
  for (int i = 1; i <= Q; i++) {
    cout << sum[C[i]][D[i]] - sum[C[i]][B[i] - 1] - sum[A[i] - 1][D[i]] + sum[A[i] - 1][B[i] - 1] << endl;
  }
  return 0;
}
