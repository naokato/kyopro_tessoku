#include <iostream>
using namespace std;

int H, W, N;
int A[100009], B[100009], C[100009], D[100009];
int Diff[1509][1509];
int CS[1509][1509];

int main() {
  cin >> H >> W >> N;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];

  for (int i = 1; i <= N; i++) {
    Diff[A[i]][B[i]] += 1;
    Diff[A[i]][D[i] + 1] -= 1;
    Diff[C[i] + 1][B[i]] -= 1;
    Diff[C[i] + 1][D[i] + 1] += 1;
  }

  // check Diff
  // for (int i = 1; i <= H; i++) {
  //   for (int j = 1; j <= W; j++) {
  //     cout << Diff[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // calculate cumlative sum
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) CS[i][j] = 0;
  }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) CS[i][j] = CS[i][j - 1] + Diff[i][j];
  }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (j >= 2) cout << " ";
      CS[i][j] = CS[i - 1][j] + CS[i][j];
      cout << CS[i][j];
    }
    cout << endl;
  }
}
