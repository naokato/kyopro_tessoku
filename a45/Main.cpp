#include <iostream>
using namespace std;

int N;
char C, A[200009];

int main() {
  cin >> N >> C;
  for (int i = 1; i <= N; i++) cin >> A[i];

  int mod = 0;
  for (int i = 1; i <= N; i++) {
    if (A[i] == 'B') mod += 1;
    else if(A[i] == 'R') mod += 2;
  }
  mod = mod % 3;
  
  bool answer;
  if (C == 'W' && mod == 0) answer = true;
  else if (C == 'B' && mod == 1) answer = true;
  else if (C == 'R' && mod == 2) answer = true;
  else answer = false;

  if (answer) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
