#define DEBUG 1
#include <iostream>
using namespace std;

int N, D, X[200009], Y[200009];

int main() {
  cin >> N >> D;
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

  int answer = 0;
  for (int i = 1; i <= D; i++) {
    int maxIncome = 0;
    int maxDate = 0;
    for (int j = 1; j <= N; j++) {
      if (i < X[j]) continue;
      if (maxIncome <= Y[j]) {
        maxIncome = Y[j];
        maxDate = j;
      }
    }
    answer += maxIncome;
    // already chosen as worked day
    X[maxDate] = 99999;
  }

  cout << answer << endl;
  return 0;
}
