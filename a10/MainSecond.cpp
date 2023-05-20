#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100009], D, L[100009], R[100009];
int leftMax[100009];
int rightMax[100009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  cin >> D;
  for (int i = 1; i <= D; i++) cin >> L[i] >> R[i];

  leftMax[0] = 0;
  for (int i = 1; i <= N; i++) {
    leftMax[i] = max(leftMax[i - 1], A[i]);
  }

  rightMax[N + 1] = 0;
  for (int i = N; i >= 1; i--) {
    rightMax[i] = max(rightMax[i + 1], A[i]);
  }

  for (int i = 1; i <= D; i++) {
    cout << max(leftMax[L[i] - 1], rightMax[R[i] + 1]) << endl;
  }
  return 0;
}
