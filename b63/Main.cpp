#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, sy, sx, gy, gx;
char c[59][59];
vector<int> G[2509];
int dist[2509];

// i=1, j=1 の時 1 になるように、
// 二次元データを一次元データに変換
int convert(int i, int j) {
  return (i - 1)  * C + j;
}

int main() {
  cin >> R >> C;
  cin >> sy >> sx;
  cin >> gy >> gx;

  int startPoint = convert(sy, sx);
  int endPonit = convert(gy, gx);

  for (int i = 1; i <= R; i++)
    for (int j = 1; j <= C; j++) cin >> c[i][j];

  // cout << startPoint << " " << endPonit << endl;
  
  for (int i = 1; i <= 2500; i++) dist[i] = -1;

  // make graph
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (c[i][j] == '#') continue;
      if (j < C && c[i][j + 1] == '.') {
        G[convert(i, j)].push_back(convert(i, j + 1));
        G[convert(i, j + 1)].push_back(convert(i, j));
      }
      if (i < R && c[i + 1][j] == '.') {
        G[convert(i, j)].push_back(convert(i + 1, j));
        G[convert(i + 1, j)].push_back(convert(i, j));
      }
    }
  }

  // for (int i = 1; i <= R*C; i++) {
  //   cout << i << ":";
  //   for (const auto& node: G[i]) cout << node << " ";
  //   cout << endl;
  // }

  queue<int> q;
  dist[startPoint] = 0;
  q.push(startPoint);
  
  while (!q.empty()) {
    const int current = q.front();
    q.pop();
    // cout << "current:" << current << endl;

    for (const auto& node: G[current]) {
      // cout << "- node:" << node << endl;
      if (dist[node] == -1) {
        dist[node] = dist[current] + 1;
        q.push(node);
      }
    }
  }

  cout << dist[endPonit] << endl;
  return 0;
}
