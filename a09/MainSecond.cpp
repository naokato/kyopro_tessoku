#include <iostream>
using namespace std;

int H, W, N, A[100009], B[100009], C[100009], D[100009];
int diff[1509][1509];
int sum[1509][1509];

int main() {
  cin >> H >> W >> N;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
  
  for (int i = 1; i <= N; i++) {
    diff[A[i]][B[i]] += 1;
    diff[C[i] + 1][B[i]] -= 1;
    diff[A[i]][D[i] + 1] -= 1;
    diff[C[i] + 1][D[i] + 1] += 1;
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      sum[i][j] = sum[i][j - 1] + diff[i][j];
    }
  }
  for (int j = 1; j <= W; j++) {
    for (int i = 1; i <= H; i++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j];
    }
  }
  
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cout << sum[i][j] << "  ";
    }
    cout << endl;
  }

  return 0;
}
