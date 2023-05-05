#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, A[100009], B[100009], C[100009];
vector<pair<int, int>> G[100009];

int cur[100009];
bool kakutei[100009];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    G[A[i]].push_back(make_pair(B[i], C[i]));
    G[B[i]].push_back(make_pair(A[i], C[i]));
  }

  for (int i = 1; i <= N; i++) kakutei[i] = false;
  for (int i = 1; i <= N; i++) cur[i] = 2000000000;

  cur[1] = 0;
  while (true) {
    int pos = -1;
    int MinDist = 2000000000;
    for (int i = 1; i <= N; i++) {
      if (kakutei[i] == true || MinDist <= cur[i]) continue;
      pos = i;
      MinDist = cur[i];
    }

    if (pos == -1) break;

    kakutei[pos] = true;
    for (const auto& node: G[pos]) {
      int nex = node.first;
      int cost = node.second;
      cur[nex] = min(cur[nex], cur[pos] + cost);
    }
  }
    
  for (int i = 1; i <= N; i++) {
    cout << cur[i] << endl;
  }
}
