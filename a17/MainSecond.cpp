#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A[100009], B[100009], dp[100009];

int main() {
  cin >> N;
  for (int i = 2; i <= N; i++) cin >> A[i];
  for (int i = 3; i <= N; i++) cin >> B[i];

  dp[1] = 0;
  dp[2] = A[2];
  for (int i = 3; i <= N; i++) {
    dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
  }
  
  vector<int> vec;
  int current = N;
  while (true) {
    vec.push_back(current);
    if (current == 1) break;
    if (dp[current - 1] + A[current] == dp[current]) {
      current = current - 1;
    } else {
      current = current - 2;
    }
  }

  reverse(vec.begin(), vec.end());
  cout << vec.size() << endl;
  for (const auto num: vec) {
    cout << num << " ";
  }

  return 0;
}
