#define DEBUG 0
#include <iostream>
using namespace std;

int N;
int A[100009], B[100009];
int DP[100009];

int main() {
  // input
  cin >> N;
  for (int i = 2; i <= N; i++) cin >> A[i];
  for (int i = 3; i <= N; i++) cin >> B[i];

  DP[1] = 0;
  DP[2] = A[2];
  for (int i = 3; i <= N; i++) {
    DP[i] = min(DP[i - 1] + A[i], DP[i - 2] + B[i]);
  }
  #if DEBUG
  for (int i = 1; i <= N; i++) {
    cout << DP[i] << " ";
  }
  cout << endl;
  #endif

  cout << DP[N] << endl;
  return 0;
}
