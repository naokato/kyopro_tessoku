#include <iostream>
using namespace std;

int N, Q, A[100009], L[100009], R[100009];
int sum[100009];

int main() {
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];

  sum[0] = 0;
  for (int i = 1; i <= N; i++) sum[i] = sum[i - 1] + A[i];
  
  for (int i = 1; i <= Q; i++) {
    cout << sum[R[i]] - sum[L[i] - 1] << endl;
  }
  return 0;
}
