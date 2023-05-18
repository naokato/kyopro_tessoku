#include <iostream>
using namespace std;

int N, K;

int main() {
  cin >> N >> K;

  long long Answer = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (K - N <= i + j && i + j <= K - 1) Answer++;
    }
  }

  cout << Answer << endl;
  return 0;
}
