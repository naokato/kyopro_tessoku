#include <iostream>
using namespace std;

int N, X[100009], Y[100009];
int Q, A[100009], B[100009], C[100009], D[100009];
int Points[1509][1509];
int CumlativeSum[1509][1509];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i];
  }
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  for (int i = 1; i <= N; i++) {
    Points[X[i]][Y[i]] += 1;
  }

  // check Points
  // for (int i = 1; i <= 1509; i++) {
  //   for (int j = 1; j <= 1509; j++) {
  //     cout << Points[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // initialize by zero
  for (int i = 0; i <= 1500; i++) {
    for (int j = 0; j <= 1500; j++) {
      CumlativeSum[i][j] = 0;
    }
  }
  // calculate cumlative sum
  for (int i = 1; i <= 1500; i++) {
    for (int j = 1; j <= 1500; j++) {
      CumlativeSum[i][j] = CumlativeSum[i][j - 1] + Points[i][j];
    }
  }
  for (int j = 1; j <= 1500; j++) {
    for (int i = 1; i <= 1500; i++) {
      CumlativeSum[i][j] = CumlativeSum[i - 1][j] + CumlativeSum[i][j];
    }
  }

  // answer
  for (int i = 1; i <= Q; i++) {
    cout << CumlativeSum[C[i]][D[i]] - CumlativeSum[A[i] - 1][D[i]] - CumlativeSum[C[i]][B[i] - 1] + CumlativeSum[A[i] - 1][B[i] - 1] << endl;
  }
  return 0;
}
