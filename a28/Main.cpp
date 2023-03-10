#include <iostream>
using namespace std;

int N, A[100009];
char T[100009];

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> T[i] >> A[i];

  int current = 0;
  for (int i = 1; i <= N; i++) {
    switch (T[i]) {
      case '+':
        current += A[i];
        break;
      case '-':
        current -= A[i];
        break;
      case '*':
        current *= A[i];
        break;
    }
    if (current < 0) current += 10000;
    current = current % 10000;
    cout << current << endl;
  }
  return 0;
}
