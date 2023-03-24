#include <iostream>
#include <algorithm>
using namespace std;

int D, N, L[10009], R[10009], H[10009];
int limit[369];

int main() {
  cin >> D >> N;
  for (int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> H[i];
  
  // initialize
  for (int i = 1; i <= D; i++) limit[i] = 24;

  for (int i = 1; i <= N; i++) {
    for (int j = L[i]; j <= R[i]; j++) limit[j] = min(limit[j], H[i]);
  }

  int answer = 0;
  for (int i = 1; i <= D; i++) answer += limit[i];
  cout << answer << endl;
  return 0;
}
