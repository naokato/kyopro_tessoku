#define DEBUG 0
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int A[100009], B[100009];
int DP[100009];

int main() {
  // input
  cin >> N;
  for (int i = 2; i <= N; i++) cin >> A[i];
  for (int i = 3; i <= N; i++) cin >> B[i];

  DP[1] = 0;
  DP[2] = A[2];
  for (int i = 3; i <= N; i++) {
    DP[i] = min(DP[i - 1] + A[i], DP[i - 2] + B[i]);
  }
  #if DEBUG
  for (int i = 1; i <= N; i++) {
    cout << DP[i] << " ";
  }
  cout << endl;
  #endif

  // follow the shortest path
  vector<int> vec;
  int i = N;
  while (true) {
    vec.push_back(i);
    if (i == 1) break;
    if (DP[i - 1] + A[i] == DP[i]) {
      i = i - 1;
    } else {
      i = i - 2;
    }
  }

  // change order to begin with first place
  reverse(vec.begin(), vec.end());

  // answer
  cout << vec.size() << endl;

  for (int i = 0; i < vec.size(); i++) {
    if (i > 0) cout << " ";
    cout << vec[i];
  }
  // for_each(rbegin(vec), rend(vec), [](const auto& item) {
  //   cout << item << " ";
  // });

  return 0;
}
