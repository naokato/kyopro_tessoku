#include <iostream>
using namespace std;

int main() {
  string N;
  cin >> N;
  int sum = 0;
  for (int i = 0; i < N.length(); i++) {
    if (N[i] == '1') sum += (1 << (N.length() - 1 - i));
  }
  cout << sum << endl;
  return 0;
}
