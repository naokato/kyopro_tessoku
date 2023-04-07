#include <iostream>
#include <algorithm>
using namespace std;

long long N, Q, L[100009], R[100009];
string S;
long long T[100009];
long long reversedT[100009];
long long H[100009];
long long reversedH[100009];

const long long mod = 2147483674;
// base B numeral system
long long B = 100LL;
long long BPower[100009];

long long hash_value(long long A[], int l, int r) {
  long long result = A[r] - (A[l - 1] * BPower[r - l + 1] % mod) ;
  if (result < 0) result += mod;
  return result;
}

int main() {
  cin >> N >> Q;
  cin >> S;
  for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];
 
  // int converted version of S;
  for (int i = 1; i <= N; i++) T[i] = (S[i - 1] - 'a') + 1;

  // int converted version of reversed S;
  reverse(S.begin(), S.end());
  for (int i = 1; i <= N; i++) reversedT[i] = (S[i - 1] - 'a') + 1;

  // calculate B^i in advance
  BPower[0] = 1;
  for (int i = 1; i <= N; i++) BPower[i] = BPower[i - 1] * B % mod;

  // hash of first i chars of S;
  H[0] = 0;
  for (int i = 1; i <= N; i++) H[i] = (B * H[i - 1] + T[i]) % mod;

  // hash of first i chars of reversed S;
  reversedH[0] = 0;
  for (int i = 1; i <= N; i++) reversedH[i] = (B * reversedH[i - 1] + reversedT[i]) % mod;

  for (int i = 1; i <= Q; i++) {
    long long hash1 = hash_value(H, L[i], R[i]);
    long long hash2 = hash_value(reversedH, N - R[i] + 1, N - L[i] + 1);
    if (hash1 == hash2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
