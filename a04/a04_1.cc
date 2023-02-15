#include <iostream>
using namespace std;

int N, Answer[11];

int main() {
  cin >> N;
  for (int i = 1; i <= 10; i++) Answer[i] = 0;
  
  int n = N;
  for (int i = 1; i <= 10; i++) {
    int r = n % 2;
    Answer[i] = r;
    n = n/2;
    if (n == 0) break;
  }

  for (int i = 10; i >= 1; i--) cout << Answer[i];
  return 0;
}
