#include <iostream>
using namespace std;

int N, Q;
int E[200009];
bool isNormal = true;

int main() {
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) E[i] = i;
  
  for (int i = 1; i <= Q; i++) {
    int type;
    int x, y;
    cin >> type;
    if (type == 1) {
      cin >> x >> y;
      if (isNormal) E[x] = y;
      else E[N + 1 - x] = y;
    } else if (type == 2) {
      isNormal = !isNormal;
    } else {
      cin >> x;
      if (isNormal) cout << E[x] << endl;
      else cout << E[N + 1 - x]  << endl;
    }
  }

  return 0;
}
