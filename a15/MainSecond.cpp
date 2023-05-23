#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, A[100009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  vector<int> vec;
  for (int i = 1; i <= N; i++) vec.push_back(A[i]);

  sort(vec.begin(), vec.end());
  decltype(vec)::iterator result = unique(vec.begin(), vec.end());
  vec.erase(result, vec.end());

  for (int i = 1; i <= N; i++) {
    int pos = lower_bound(vec.begin(), vec.end(), A[i]) - vec.begin();
    cout << pos + 1 << " ";
  }

  return 0;
}
