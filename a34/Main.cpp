#include <iostream>
using namespace std;

int N, X, Y, A[100009];
int grundy[100009];

int main() {
  cin >> N >> X >> Y;
  for (int i = 1; i <= N; i++) cin >> A[i];

  // 各 A[i] で grundy 数列は同じ
  for (int i = 1; i <= 100000; i++) {
    if (i < X) {
      grundy[i] = 0;
      continue;
    }
    // grundy が i となるような遷移が可能かどうか
    bool Transit[3] = { false, false, false };
    if (i >= X) Transit[grundy[i - X]] = true;
    if (i >= Y) Transit[grundy[i - Y]] = true;

    if (!Transit[0]) grundy[i] = 0;
    else if (!Transit[1]) grundy[i] = 1;
    else grundy[i] = 2;
  }

  int xorsum = 0;
  for (int i = 1; i <= N; i++) {
    xorsum = xorsum ^ grundy[A[i]]; 
  }
  if (xorsum == 0) cout << "Second" << endl;
  else cout << "First" << endl;
  return 0;
}
