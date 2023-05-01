#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
stack<int> S;
bool alreadyHaveAnswer = false;
bool reached[100009];

void dfs(int current) {
  reached[current] = true;
  if (alreadyHaveAnswer) return;

  S.push(current);

  if (current == N) {
    alreadyHaveAnswer = true;
    return;
  }

  for (const auto& node: G[current]) {
    if (!reached[node]) {
      dfs(node);
    }
  }

  if (!alreadyHaveAnswer) S.pop();
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

  vector<int> answer;
  while (!S.empty()) {
    answer.push_back(S.top());
    S.pop();
  }

  for (auto it = answer.rbegin(); it != answer.rend(); ++it) {
    cout << *it << " ";
  }

  return 0;
}
