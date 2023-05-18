#include <iostream>
using namespace std;

int N, X, A[109];

int main() {
  cin >> N >> X;
  for (int i = 1; i <= N; i++) cin >> A[i];

  bool Answer = false;
  for (int i = 1; i <= N; i++) {
    if (A[i] == X) Answer = true;
  }

  if (Answer) cout << "Yes" << endl;
  else cout << "No" << endl;
}
