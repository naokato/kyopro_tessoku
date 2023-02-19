#include <iostream>
using namespace std;

int N, X, A[100009];

int search(int x) {
  int pos = lower_bound(A + 1, A + N + 1, x) - A;
  if (pos <= N && A[pos] == x) return pos;
  return -1;
}

int main() {
  cin >> N >> X;
  for (int i = 1; i <= N; i++) cin >> A[i];


  int Answer = search(X);
  cout << Answer << endl;
  return 0;
}
