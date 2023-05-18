#include <iostream>
using namespace std;

int D, N, L[100009], R[100009];
int diff[100009];
int sum[100009];

int main() {
  cin >> D >> N;
  for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];
  
  for (int i = 1; i <= N; i++) {
    diff[L[i]] += 1;
    diff[R[i] + 1] -= 1;
  }

  sum[0] = 0;
  for (int i = 1; i <= D; i++) sum[i] = sum[i - 1] + diff[i];
  for (int i = 1; i <= D; i++) cout << sum[i] << endl;

  return 0;
}
