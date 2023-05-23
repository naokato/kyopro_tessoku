#include <iostream>
#include <algorithm>
using namespace std;

long long N, K, A[1009], B[1009], C[1009], D[1009];
long long SumAB[1000009], SumCD[1000009];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int i = 1; i <= N; i++) cin >> B[i];
  for (int i = 1; i <= N; i++) cin >> C[i];
  for (int i = 1; i <= N; i++) cin >> D[i];
  
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      SumAB[(i - 1) * N + j] = A[i] + B[j];
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      SumCD[(i - 1) * N + j] = C[i] + D[j];
    }
  }

  sort(SumCD + 1, SumCD + N * N + 1);
  
  bool Answer = false;
  for (int i = 1; i <= N * N; i++) {
    long long pos = lower_bound(SumCD + 1, SumCD + N * N + 1, K - SumAB[i]) - SumCD;
    if (pos <= N * N && SumCD[pos] == K - SumAB[i])  {
      Answer = true;
      //cout << "pos="  << pos << " CD=" << SumCD[pos] << " K=" << K  << ", AB="  << SumAB[i] << endl;
    }
  }

  if (Answer) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
