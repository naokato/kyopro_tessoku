#include <iostream>
using namespace std;

int N, K;
int A[100009];
// for each i of N, R[i] means max index n such that A[i] + ... + A[n] <= K
int R[100009];
long long CS[100009];

int main() {
  // input
  cin >> N >> K;

  for (int i = 1; i <= N; i++) cin >> A[i];
  
  // calculate cumlative sum
  CS[0] = 0;
  for (int i = 1; i <= N; i++) CS[i] = CS[i - 1] + A[i];
  // check
  for (int i = 1; i <= N; i++) cout << CS[i] << " ";
  cout << endl;

  for (int i = 1; i <= N; i++) {
    // initialize index
    if (i == 1) {
      R[i] = 0;
    } else {
      R[i] = R[i - 1];
    }
    
    // count up till sum exceed K
    // CS[R[i] + 1] - CS[i - 1] <= K means A[i] + ... + A[R[i] + 1] <= K
    while(R[i] < N && CS[R[i] + 1] - CS[i - 1] <= K) {
      R[i] += 1;
    }
  }

  // check
  // for (int i = 1; i <= N; i++) cout << R[i] << " ";
  // cout << endl;
  
  long long Answer = 0;
  for (int i = 1; i <= N; i++) {
    Answer += R[i] - (i - 1); 
  }
  cout << Answer << endl;
  return 0;
}
