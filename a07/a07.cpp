#include <iostream>
using namespace std;

int D, Sabun[100009], attendanceCount[100009];
int N, L[100009], R[100009];

int main() {
  // input
  cin >> D >> N;
  for (int i = 1; i<= N; i++) cin >> L[i] >> R[i];

  // calculate sabun
  for (int i = 1; i <= N; i++) {
    Sabun[L[i]] += 1;
    Sabun[R[i] + 1] -= 1;
  }

  // check sabun
  // for (int i = 1; i<= D; i++) cout << Sabun[i] << " ";

  // calculate daily attendance count by using cumulative sum method
  attendanceCount[0] = 0;
  for (int i = 1; i <= D; i++) {
    attendanceCount[i] = attendanceCount[i - 1] + Sabun[i];
    cout << attendanceCount[i] << endl;
  }
  return 0;
}
