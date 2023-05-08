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

int N, P[159];
int M, A[159], B[159];
MaximumFlow Z;

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> P[i];
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];

  int Offset = 0;
  Z.init(N);
  for (int i = 1; i <= N; i++) {
    if (P[i] >= 0) {
      // start node to i
      Z.add_edge(N + 1, i, P[i]);
      Offset += P[i];
    } else {
      // i to end node
      Z.add_edge(i, N + 2, - P[i]);
    }
  }

  for (int i = 1; i <= M; i++) {
    Z.add_edge(A[i], B[i], 1000000000);
  }

  int Answer = Offset - Z.max_flow(N + 1, N + 2);
  cout << Answer << endl;

  return 0;
}
