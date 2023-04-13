#include <iostream>
using namespace std;

class SegmentTree {
public:
  int data[600000], size = 1;

  void init(int N) {
    while(size < N) size *= 2;
    for (int i = 1; i < size * 2; i++) data[i] = 0;
  }

  void update(int pos) {
    pos = pos + size - 1;
    data[pos] += 1;
    
    while (pos >= 2) {
      pos /= 2;
      data[pos] = data[pos * 2] + data[pos * 2 + 1];
    }
  }

  int query(int l, int r, int a, int b, int u) {
    if (b <= l || r <= a ) return 0;
    if (l <= a && b <= r) return data[u];

    int m = (a + b) / 2;
    int Answer1 = query(l, r, a, m, u * 2);
    int Answer2 = query(l, r, m, b, u * 2 + 1);
    return Answer1 + Answer2;
  }
};

int N, A[150009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  
  SegmentTree t;
  t.init(N);
  long long Answer = 0;
  for (int j = 1; j <= N; j++) {
    Answer += t.query(A[j] + 1, N + 1, 1, t.size + 1, 1);
    t.update(A[j]);
  }
  cout << Answer << endl;

  return 0;
}
