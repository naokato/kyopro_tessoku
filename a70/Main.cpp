#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, A[19];
int M, X[109], Y[109], Z[109];
int dist[1033];
vector<int> G[1033];

int GetNext(int pos, int idx) {
  int State[19];

  for (int i = 1; i <= N; i++) {
    int wari = (1 << (i - 1));
    State[i] = (pos / wari) % 2;
  }

  // reverse
  State[X[idx]] = 1 - State[X[idx]];
  State[Y[idx]] = 1 - State[Y[idx]];
  State[Z[idx]] = 1 - State[Z[idx]];

  int ret = 0;
  for (int i = 1; i <= N; i++) {
    if (State[i] == 1) ret += (1 << (i - 1));
  }

  return ret;
}

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int j = 1; j <= M; j++) cin >> X[j] >> Y[j] >> Z[j];

  // add edges
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 1; j <= M; j++) {
      int NextState = GetNext(i, j); 
      G[i].push_back(NextState);
    }
  }

  int Goal = (1 << N) - 1;
  int Start = 0;
  for (int i = 1; i <= N; i++) {
    if (A[i] == 1) Start += (1 << (i - 1));
  }

  queue<int> Q;
  for (int i = 0; i < (1 << N); i++) dist[i] = -1;
  dist[Start] = 0;
  Q.push(Start);

  while (!Q.empty()) {
    int pos = Q.front();
    Q.pop();
    for (int nex: G[pos]) {
      if (dist[nex] == -1) {
        dist[nex] = dist[pos] + 1;
        Q.push(nex);
      }
    }
  }

  cout << dist[Goal] << endl;
  return 0;
}
