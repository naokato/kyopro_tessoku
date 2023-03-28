#include <iostream>
using namespace std;

int N, A[509][509], Q;
int T[509];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) cin >> A[i][j];
  cin >> Q;

  for (int i = 1; i <= N; i++) T[i] = i;

  for (int i = 1; i <= Q; i++) {
    int type, x, y;
    cin >> type >> x >> y;

    if (type == 1) {
      int tmp = T[x];
      T[x] = T[y];
      T[y] = tmp;
    } else if (type == 2) {
      cout << A[T[x]][y] << endl;
    }
  }
  return 0;
}
