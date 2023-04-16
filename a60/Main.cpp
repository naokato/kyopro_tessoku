#include <iostream>
#include <stack>
using namespace std;

int N, A[200009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  stack<pair<int, int>> s;

  // 初日に起算日は無い
  cout << -1 << endl;
  s.emplace(1, A[1]);
  for (int i = 2; i <= N; i++) {
    while (!s.empty() && A[i] >= s.top().second) {
      s.pop();
    }
    if (s.empty()) {
      cout << -1 << endl;
    } else {
      cout << s.top().first << endl;
    }

    s.emplace(i, A[i]);
  }
  
  return 0;
}
