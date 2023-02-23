#define USE_DEBUG 0
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> Enumerate(vector<long long> A) {
  vector<long long> SumList;
  for (int i = 0; i < (1 << A.size()); i++) {
    long long sum = 0;
    for (int j = 0; j < A.size(); j++) {
      int wari = 1 << j;
      if ((i / wari) % 2 == 1) sum += A[j];
    }
    SumList.push_back(sum);
  }
  return SumList;
}

void display(vector<long long> &A) {
  #if USE_DEBUG
  for (const auto &item: A) {
    cout << item << " ";
  }
  cout << endl;
  #endif
}

long long N, K;
long long A[39];

int main() {
  // input
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  vector<long long> L1, L2;
  for (int i = 1; i <= N/2; i++) L1.push_back(A[i]);
  for (int i = N/2 + 1; i <= N; i++) L2.push_back(A[i]);
  display(L1);
  display(L2);

  // calculate sum
  vector<long long> Sum1 = Enumerate(L1);
  vector<long long> Sum2 = Enumerate(L2);
  display(Sum1);
  display(Sum2);

  // sort
  sort(Sum1.begin(), Sum1.end());
  sort(Sum2.begin(), Sum2.end());
  display(Sum1);
  display(Sum2);

  // answer
  for (int i = 0; i < Sum1.size(); i++) {
    int pos = lower_bound(Sum2.begin(), Sum2.end(), K - Sum1[i]) - Sum2.begin();
    if (pos < Sum2.size() && Sum2[pos] == K - Sum1[i]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
