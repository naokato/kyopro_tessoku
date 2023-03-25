#define DEBUG 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L[300009], R[300009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

  vector<pair<int, int>> v;
  for (int i = 1; i <= N; i++) v.emplace_back(L[i], R[i]);

  sort(v.begin(), v.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.second < rhs.second;
  });

  #if DEBUG
  for (const auto& item: v) {
    cout << item.first << " " <<  item.second << endl;
  }
  #endif

  int current = 0;
  int answer = 0;
  for (const auto& item: v) {
    if (current <= item.first) {
      current = item.second;
      answer++;
    }
  }

  cout << answer << endl;

  return 0;
}
