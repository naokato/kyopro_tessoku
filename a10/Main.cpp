#include <iostream>
using namespace std;

int N, A[100009];
int D, L[100009], R[100009];
// Cumlative Sum (capa * room)
int CS[109][100009];

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  cin >> D;
  for (int i = 1; i <= D; i++) cin >> L[i] >> R[i];

  // calculate room capa/room number
  for (int i = 1; i <= N; i++) {
    CS[A[i]][i] += 1;
  }
  // check
  //for (int i = 1; i <= 6; i++) {
  //  for (int j = 1; j <= N; j++) {
  //    cout << CS[i][j] << " ";
  //  }
  //  cout << endl;
  //}
  //cout << endl;

  // calculate cumlative sum
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= N; j++) {
      CS[i][j] = CS[i][j - 1] + CS[i][j];
    }
  }
  // check
  //for (int i = 1; i <= 6; i++) {
  //  for (int j = 1; j <= N; j++) {
  //    cout << CS[i][j] << " ";
  //  }
  //  cout << endl;
  //}

  for (int i = 1; i <= D; i++) {
    for (int j = 100; j >= 1; j--) {
      int num = CS[j][N] - (CS[j][R[i]] - CS[j][L[i] - 1]);
      if (num > 0) {
        cout << j;
        break;
      }
    }
    cout << endl;
  }
}
