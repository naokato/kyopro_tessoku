#define DEBUG 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, X[100009], Y[100009];
// (ソート済の) i番目までの最長の箱数
int dp[100009];
int L[100009];

void printL() {
  #if DEBUG
  for (int i = 1; i <= N; i++) {
    cout << L[i] << " ";
  }
  cout << endl;
  #endif
}

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

  // sort
  // X: asc
  // Y: desc
  // Y を降順にする事で、Y の比較だけで X が同一のケースを弾ける
  vector<pair<int, int>> XY;
  for (int i = 1; i <= N; i++) XY.push_back({X[i], -Y[i]});
  sort(XY.begin(), XY.end());

  #if DEBUG
  cout << "--- XY ---" << endl;
  for (const auto& item: XY) cout << item.first << " " << -item.second << endl;
  cout << endl;
  #endif
  
  // prepare sorted Y
  vector<int> sortedY;
  for (const auto& item: XY) {
    sortedY.push_back(-item.second);
  }
  
  #if DEBUG
  cout << "--- sortedY ---" << endl;
  for (const auto& item: sortedY) cout << item << endl;
  cout << endl;
  #endif

  // dynamic programing
  int SIZE = 0;
  for (int i = 1; i <= N; i++) {
    int yAtI = sortedY[i - 1];
    int pos = lower_bound(L + 1, L + SIZE + 1, yAtI) - L;
    // yAti より小さい最大の値を持つのは pos - 1番目であり、その時の箱の数は pos -1
    // それをi番目の箱に入れることが出来るから、(pos - 1) + 1
    dp[i] = pos;
    L[dp[i]] = yAtI;
    if (dp[i] > SIZE) SIZE++;
    printL();
  }

  #if DEBUG
  cout << "--- dp ---" << endl;
  for (int i = 1; i <= N; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
  #endif

  cout << SIZE << endl;
}
