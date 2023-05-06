#include <iostream>
#include <vector>
using namespace std;

int N, A[100009];
vector<int> Child[100009];
int Answer[100009];

int main() {
  cin >> N;
  for (int i = 2; i <= N; i++) cin >> A[i];

  for (int i = 2; i <= N; i++) {
    Child[A[i]].push_back(i);
  }

  Answer[1] = N - 1;
  for (int i = N; i >= 2; i--) {
    if (Child[i].empty()) {
      Answer[i] = 0;
      continue;
    }
    for (const auto& node: Child[i]) {
      Answer[i] += Answer[node];
      Answer[i] += 1;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (i != 1) cout << " ";
    cout << Answer[i];
  }

  return 0;
}
