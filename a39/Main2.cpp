#include <iostream>
using namespace std;

int N, L[300009], R[300009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

  int answer = 0;
  int current = 0;

  while (true) {
    int minEnd = 86401;
    for (int i = 1; i <= N; i++) {
      if (current > L[i]) continue;
      minEnd = min(minEnd, R[i]);
    }
    if (minEnd == 86401) break;
    current = minEnd;
    answer++;
  }

  cout << answer << endl;
  return 0;
}
