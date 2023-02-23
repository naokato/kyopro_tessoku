#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[39];
long long P[33000], Q[33000];

int main() {
  // input
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];

  int firstHalfCount = N / 2;
  int sizeOfP = (1 << firstHalfCount);
  int secondHalfCount = (N + 1) / 2;
  int sizeOfQ = (1 << secondHalfCount);

  // calculate first half
  for (int i = 1; i < sizeOfP; i++) {
    int sum = 0;
    for (int j = 1; j <= firstHalfCount; j++) {
      int wari = 1 << (j - 1);
      if ((i / wari) % 2 == 1) sum += A[j];
    }
    P[i] = sum;
  }
  // check
  // for (int i = 1; i < sizeOfP; i++) {
  //   cout << P[i] << " ";
  // }
  // cout << endl;
  
  // calculate second half
  for (int i = 1; i < sizeOfQ; i++) {
    int sum = 0;
    for (int j = 1; j <= secondHalfCount; j++) {
      int wari = 1 << (j - 1);
      if ((i / wari) % 2 == 1) sum += A[firstHalfCount + j];
    }
    Q[i] = sum;
  }
  // check
  // for (int i = 1; i < sizeOfQ; i++) {
  //   cout << Q[i] << " ";
  // }
  // cout << endl;


  // sort
  sort(P + 1, P + sizeOfP);
  // for (int i = 1; i < sizeOfP; i++) {
  //   cout << P[i] << " ";
  // }
  // cout << endl;
  
  // answer
  bool Answer = false;
  for (int i = 1; i < sizeOfQ; i++) {
    // cout << "K - Q[i] = " << K - Q[i] << endl;
    int pos = lower_bound(P + 1, P + sizeOfP, K - Q[i]) - P;
    // cout << pos << ":" << P[pos] << " " << endl;

    if (pos < sizeOfP && P[pos] + Q[i] == K) {
      Answer = true;
      break;
    }
  }
  if (Answer) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
