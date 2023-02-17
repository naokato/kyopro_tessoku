#include <iostream>
using namespace std;

int N;
int A[100009], B[100009], C[100009], D[100009];
int Diff[1509][1509];
int CS[1509][1509];
int answer;

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
  
  // calculate diff
  for (int i = 1; i <= N; i++) {
    Diff[A[i]][B[i]] += 1;
    Diff[A[i]][D[i]] -= 1;
    Diff[C[i]][B[i]] -= 1;
    Diff[C[i]][D[i]] += 1;
  }

  // check diff
  // for (int i = 0; i <= 5; i++) {
  //   for (int j = 0; j <= 5; j++) {
  //     cout << Diff[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  // calculate cumlative sum
  for (int i = 0; i <= 1500; i++) {
    CS[i][0] = Diff[i][0];
    for (int j = 1; j <= 1500; j++) CS[i][j] = 0;
  }
  for (int i = 0; i <= 1500; i++) {
    for (int j = 1; j <= 1500; j++) CS[i][j] = CS[i][j - 1] + Diff[i][j];
  }
  for (int j = 0; j <= 1500; j++) {
    for (int i = 1; i <= 1500; i++) CS[i][j] = CS[i - 1][j] + CS[i][j];
  }
  
  // check cumlative sum
  // for (int i = 0; i <= 5; i++) {
  //   for (int j = 0; j <= 5; j++) {
  //     cout << CS[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  
  // answer
  for (int i = 0; i <= 1499; i++) {
    for (int j = 0; j <= 1499; j++) {
      if (CS[i][j] != 0) answer++;
    }
  }

  cout << answer << endl;
  return 0;
}
