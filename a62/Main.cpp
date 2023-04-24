#include <iostream>
#include <vector>
using namespace std;

int N, M, A[100009], B[100009];

vector<int> G[100009];
bool reached[100009];

void dfs(int current) {
  reached[current] = true;
  
  for (const auto& node: G[current]) {
    if (!reached[node]) dfs(node);
  }
  return;
}

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];

  for (int i = 1; i <= N; i++) reached[i] = false;
  
  for (int i = 1; i <= M; i++) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  dfs(1);

  // for (int i = 1; i <= N; i++) cout << reached[i] << endl;

  bool connected = true;
  for (int i = 1; i <= N; i++) {
    if (!reached[i]) connected = false;
  }

  if (connected) cout << "The graph is connected." << endl;
  else cout << "The graph is not connected." << endl;

  return 0;
}
