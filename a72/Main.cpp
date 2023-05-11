#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, K;
int Answer = 0;
char c[19][109], d[19][109];

// O(HW + Wlog(W))
int paintRow(int remaining_steps) {
  vector<pair<int, int>> Column;
  for (int j = 1; j <= W; j++) {
    int cnt = 0;
    for (int i = 1; i <= H; i++) {
      if (d[i][j] == '.') cnt += 1;
    }
    Column.push_back(make_pair(cnt, j));
  }

  sort(Column.begin(), Column.end());
  reverse(Column.begin(), Column.end());

  for (int j = 0; j < remaining_steps; j++) {
    int idx = Column[j].second;
    for (int i = 1; i <= H; i++) d[i][idx] = '#';
  }

  int ret = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (d[i][j] == '#') ret += 1;
    }
  }
  return ret;
}

int main() {
  cin >> H >> W >> K;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> c[i][j];
    }
  }

  // for each way to choose rows
  // O((2^H) (HW + log(W)))
  for (int t = 0; t < (1 << H); t++) {
    // initialize d[i][j]
    for (int i = 1; i <= H; i++) {
      for (int j = 1; j <= W; j++) {
        d[i][j] = c[i][j];
      }
    }
  
    int remaining_steps = K;
    // paint chosen rows
    for (int i = 1; i <= H; i++) {
      int wari = (1 << (i - 1));
      if ((t / wari) % 2 == 0)  continue;
      remaining_steps -= 1;
      for (int j = 1; j <= W; j++) d[i][j] = '#';
    }

    // if remapinnig steps left, then paint columns
    if (remaining_steps >= 0) {
      int SubAnswer = paintRow(remaining_steps);
      Answer = max(Answer, SubAnswer);
    }
  }

  cout << Answer << endl;
  return 0;
}
