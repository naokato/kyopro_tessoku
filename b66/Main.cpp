#include <iostream>
#include <vector>
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

int N, M;
int A[100009], B[100009];
int Q;
int Query[100009];
int x[100009];
int u[100009], v[100009];

int main() {
  // input
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];
  
  bool connectAtLast[100009];
  for (int i = 1; i <= M; i++) connectAtLast[i] = true;
  
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    cin >> Query[i];
    if (Query[i] == 1) {
      cin >> x[i];
      connectAtLast[x[i]] = false;
    }
    if (Query[i] == 2) {
      cin >> u[i] >> v[i];
    }
  }
  
  // intialize union find tree
  UnionFind UF;
  UF.init(N);

  // connect lines in advance which will not be suspended finally
  for (int i = 1; i <= M; i++) {
    if (connectAtLast[i]) UF.unite(A[i], B[i]);
  }

  // execute query in reverse order to solve with union find tree
  vector<bool> Answer;
  for (int i = Q; i >= 1; i--) {
    if (Query[i] == 1) {
      UF.unite(A[x[i]], B[x[i]]);
      continue;
    }
    if (Query[i] == 2) {
      if(UF.same(u[i], v[i])) Answer.push_back(true);
      else Answer.push_back(false);
    }
  }

  reverse(Answer.begin(), Answer.end());
  for (bool answer: Answer) {
    if (answer) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
