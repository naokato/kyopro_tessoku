#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long A[100009], B[100009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

  long long plusPlus = 0;
  long long plusMinus = 0;
  long long minusPlus = 0;
  long long minusMinus = 0;
  for (int i = 1; i <= N; i++) {
    if (A[i] + B[i] >= 0) plusPlus += A[i] + B[i];
    if (A[i] - B[i] >= 0) plusMinus += A[i] - B[i];
    if (-A[i] + B[i] >= 0) minusPlus += -A[i] + B[i];
    if (-A[i] - B[i] >= 0) minusMinus += -A[i] - B[i];
  }

  long long answer = max({plusPlus, plusMinus, minusPlus, minusMinus});
  cout << answer << endl;
  return 0;
}
