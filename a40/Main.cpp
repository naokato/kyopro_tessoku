#include <iostream>
using namespace std;

long long N, A[200009];
long long C[109];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  
  for (int i = 1; i <= N; i++) {
    C[A[i]]++;
  }
  
  long long answer = 0;
  for (int i = 1; i <= 100; i++) {
    if (C[i] <= 2) continue;
    answer += C[i]* (C[i] - 1) * (C[i] -2 ) / 6;
  }
  cout << answer << endl;
  return 0;
}
