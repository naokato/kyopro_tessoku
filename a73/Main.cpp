#define DEBUG 0
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int N, M, A[100009], B[100009], C[100009], D[100009];
// pair of cost and position
vector<pair<long long, int>> G[8009];
// order by current const asc
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
long long current[8009];
bool kakutei[8009];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
  
  for (int i = 1; i <= N; i++) {
    kakutei[i] = false;
    current[i] = 2000000000;
  }

  // make graph
  for (int i = 1; i <= M; i++) {
    G[A[i]].push_back(make_pair(C[i] * 10000 - D[i], B[i]));
    G[B[i]].push_back(make_pair(C[i] * 10000 - D[i], A[i]));
  }

  #if DEBUG
  for (int i = 1; i <= N; i++) {
    cout << i << endl;
    for (const auto& node: G[i]) {
      const long long cost = node.first;
      const int nextPos  = node.second;
      cout << " - cost=" << cost << "/next position=" << nextPos << endl;
    }
  }
  #endif

  current[1] = 0;
  Q.push(make_pair(current[1], 1));

  while (!Q.empty()) {
    const int pos = Q.top().second;
    Q.pop();

    if (kakutei[pos]) continue;

    kakutei[pos] = true;

    for (const auto& next: G[pos]) {
      const long long cost = next.first;
      const int nextPos = next.second;
      if (current[pos] + cost < current[nextPos]) {
        current[nextPos] = current[pos] + cost;
        Q.push(make_pair(current[nextPos], nextPos));
      }
    }
  }

  const int treeCount = 10000 - (current[N] % 10000);
  const long long total = (current[N] + treeCount) / 10000;
  cout << total << " " << treeCount << endl;
  return 0;
}
