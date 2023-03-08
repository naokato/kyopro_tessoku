#include <iostream>
#include <cmath>
using namespace std;

int N;
bool Deleted[1000009];

int main() {
  cin >> N;
  for (int i = 2; i <= N; i++) Deleted[i] = false;

  // エラトステネスのふるい
  for (int i = 2; i * i <= N; i++) {
    if (Deleted[i] == true) continue;
    for (int j = i * 2; j <= N; j += i) Deleted[j] = true;
  }

  for (int i = 2; i <= N; i++) {
    if (Deleted[i] == false) cout << i << endl;
  }

  return 0;
}
