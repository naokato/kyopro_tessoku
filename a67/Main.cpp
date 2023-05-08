#define DEBUG 0
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class UnionFind {
  public:
  int par[100009];
  int siz[100009];

  void init(int N) {
    for (int i = 1; i <= N; i++) {
      par[i] = -1;
      siz[i] = 1;
    }
  }

  int root(int x) {
    while (true) {
      if (par[x] == -1) break;
      x = par[x];
    }
    return x;
  }

  void unite(int u, int v) {
    int RootU = root(u);
    int RootV = root(v);
    if (RootU == RootV) return;
    if (siz[RootU] < siz[RootV]) {
      par[RootU] = RootV;
      siz[RootV] = siz[RootU] + siz[RootV];
    } else {
      par[RootV] = RootU;
      siz[RootU] = siz[RootU] + siz[RootV];
    }
  }

  bool same(int u, int v) {
    if (root(u) == root(v)) return true;
    return false;
  }
};

int N, M, A[100009], B[100009], C[100009];
vector<tuple<int, int, int>> vec;

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    vec.emplace_back(A[i], B[i], C[i]);
  }

  // kruscal algorithm
  // sort by weight
  sort(vec.begin(), vec.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<2>(a) < get<2>(b);
  });

  #if DEBUG
  for (const auto& item: vec) {
    cout << std::get<0>(item) << " " << get<1>(item) << " " << get<2>(item) << endl;
  }
  #endif

  // initialize union find tree
  UnionFind UF;
  UF.init(N);

  int max = 0;
  for (const auto& item: vec) {
    const int a = get<0>(item);
    const int b = get<1>(item);
    const int c = get<2>(item);
    if (!UF.same(a, b)) {
      UF.unite(a, b);
      max += c;
    }
  }

  cout << max << endl;
  return 0;
}
