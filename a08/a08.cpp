#include <iostream>
using namespace std;

int H, A[100009], C[100009];
int W, B[100009], D[100009];
int X[1509][1509], CumlativeSum[1509][1509];
int Q;

int main() {
  // input
  cin >> H >> W;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> X[i][j]; 
    }
  }
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  // calculate cumlative sum for 2-dimension
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      CumlativeSum[i][j] = CumlativeSum[i][j - 1] + X[i][j];
    }
  }
  for (int j = 1; j <= W; j++) {
    for (int i = 1; i <= H; i++) {
      CumlativeSum[i][j] = CumlativeSum[i - 1][j] + CumlativeSum[i][j];
    }
  }

  // check CumlativeSum
  // for (int i = 1; i <= H; i++) {
  //   for (int j = 1; j <= W; j++) {
  //     cout << CumlativeSum[i][j] << " "; 
  //   }
  //   cout << endl;
  // }

  for (int i = 1; i <= Q; i++) {
    cout << CumlativeSum[C[i]][D[i]] - CumlativeSum[A[i] - 1][D[i]] - CumlativeSum[C[i]][B[i] - 1] + CumlativeSum[A[i] - 1][B[i] - 1] << endl;
  }
  return 0;
}
