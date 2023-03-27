#include <iostream>
using namespace std;

int N;
char S[200009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> S[i];

  char current;
  int count = 0;
  current = S[1];
  count++;
  for (int i = 2; i <= N; i++) {
    if (current == S[i]) {
      count++;
    } else {
      current = S[i];
      count = 1;
    }

    if (count >= 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}
