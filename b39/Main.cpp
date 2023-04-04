#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, D, X[200009], Y[200009];
// i 日目から開始可能な仕事の給与リスト
vector<int> G[200009];

int main() {
  cin >> N >> D;
  for (int i = 1; i <= N; i++) {
    cin >> X[i] >> Y[i];
    G[X[i]].push_back(Y[i]);
  }

  int answer = 0;
  priority_queue<int> q;
  for (int i = 1; i <= D; i++) {
    for (int j: G[i]) q.push(j);
    if (!q.empty()) {
      // 現在出来る最大給与の仕事を取り出す
      answer += q.top();
      q.pop();
    }
  }

  cout << answer << endl;
  return 0;
}
