#include <iostream>
using namespace std;

int main() {
  int N, Q, A[100010], L[100010], R[100010];
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];

  int cumlativeSum[100010];
  cumlativeSum[0] = 0;
  for (int i = 1; i <= N; i++) {
    cumlativeSum[i] = cumlativeSum[i - 1] + A[i];
  }
  
  // check cumlativeSum
  // for (int i = 1; i <= N; i++) cout << cumlativeSum[i] << " ";

  for (int i = 1; i <= Q; i++) {
    int l = L[i];
    int r = R[i];
    cout << cumlativeSum[r] - cumlativeSum[l - 1] << endl;
  }
}
