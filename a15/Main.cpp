#define DEBUG 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long A[100009];

void display(vector<long long> vec) {
  # if DEBUG
  for (const auto& item: vec) cout << item << " ";
  cout << endl;
  # endif
}

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  vector<long long> SU;
  for (int i = 1; i <= N; i++) SU.push_back(A[i]);
  display(SU);

  // sort
  sort(SU.begin(), SU.end());
  display(SU);
  SU.erase(unique(SU.begin(), SU.end()), SU.end());
  display(SU);

  for (int i = 1; i <= N; i++) {
    if (i != 1) cout << " ";
    int pos = lower_bound(SU.begin(), SU.end(), A[i]) - SU.begin();
    cout << pos + 1;
  }
  return 0;
}
