#include <iostream>
using namespace std;

int N, L, K, A[1000009];

bool isAnswerLongerThan(int length) {
  int lastCut = 0;
  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (A[i] - lastCut >= length && L - A[i] >= length) {
      count += 1;
      lastCut = A[i];
    }
  }

  if (count >= K) return true;
  else return false;
}

int main() {
  cin >> N >> L >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  int left = 1;
  int right = 1000000000;
  while (left < right) {
    int M = (left + right) / 2 + 1;
    if (isAnswerLongerThan(M)) {
      left = M;
    } else {
      right = M - 1;
    }
  }

  cout << left << endl;
}
