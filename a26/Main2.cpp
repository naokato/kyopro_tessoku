#include <iostream>
#include <cmath>
using namespace std;

int Q, X[300009], N = 300000;
bool Deleted[300009];

int main() {
  cin >> Q;
  for (int i = 1; i <= Q; i++) cin >> X[i];
  for (int i = 2; i <= N; i++) Deleted[i] = false;

  // エラトステネスのふるい
  for (int i = 2; i * i <= N; i++) {
    if (Deleted[i] == true) continue;
    for (int j = i * 2; j <= N; j += i) Deleted[j] = true;
  }

  for (int i = 1; i <= Q; i++) {
    if (Deleted[X[i]] == false) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
