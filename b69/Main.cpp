#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
  int to, cap, rev;
};

class MaximumFlow {
  public:
    int size_ = 0;
    bool used[409];
    vector<Edge> G[409];

    void init(int N) {
      size_ = N;
      for (int i = 0; i <= size_; i++) G[i].clear();
    }

    void add_edge(int a, int b, int c) {
      int Current_Ga = G[a].size();
      int Current_Gb = G[b].size();
      G[a].push_back(Edge{ b, c, Current_Gb });
      G[b].push_back(Edge{ a, 0, Current_Ga });
    }

    int dfs(int pos, int goal, int F) {
      if (pos == goal) return F;
      used[pos] = true;

      for (int i = 0; i < G[pos].size(); i++) {
        if (G[pos][i].cap == 0) continue;

        if (used[G[pos][i].to] == true) continue;

        int flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

        if (flow >= 1) {
          G[pos][i].cap -= flow;
          G[G[pos][i].to][G[pos][i].rev].cap += flow;
          return flow;
        }
      }
      return 0;
    }

    int max_flow(int s, int t) {
      int Total_Flow = 0;
      while (true) {
        for (int i = 0; i <= size_; i++) used[i] = false;
        int F = dfs(s, t, 1000000000);

        if (F == 0) break;
        Total_Flow += F;
      }

      return Total_Flow;
    }
};

int N, M;
char C[59][29];
MaximumFlow Z;

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 0; j <= 23; j++) cin >> C[i][j];

  // bipartite graph and start/end
  Z.init(N + 24 + 2);
  int start = N + 24 + 1;
  int end = N + 24 + 2;

  // add edge between worker i and time j
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= 23; j++) {
      if (C[i][j] == '1') Z.add_edge(i, N + j + 1, 1);
    }
  }

  // add edge between start and workers
  for (int i = 1; i <= N; i++) {
    // provide capacity 10 to each worker 
    Z.add_edge(start, i, 10);
  }
  // add edge between end and times
  for (int j = 0; j <= 23; j++) {
    Z.add_edge(N + j + 1, end, M);
  }

  int maxFlow = Z.max_flow(start, end);
  if (maxFlow == 24 * M) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
