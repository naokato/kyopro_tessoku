#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
int dist[100009];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];
  
  for (int i = 1; i <= M; i++) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  for (int i = 1; i <= N; i++) {
    dist[i] = -1;
  }

  // start point has distance 0
  dist[1] = 0;
  queue<int> q;
  q.push(1);

  while(!q.empty()) {
    const int current = q.front();
    q.pop();

    for (const auto& node: G[current]) {
      if (dist[node] == -1) {
        q.push(node);
        dist[node] = dist[current] + 1;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << dist[i] << endl;
  }

  return 0;
}
