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
int A[409], B[409], C[409];
MaximumFlow Z;

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];

  Z.init(N);

  for (int i = 1; i <= M; i++) {
    Z.add_edge(A[i], B[i], C[i]);
  }
  cout << Z.max_flow(1, N) << endl;
  return 0;
}
