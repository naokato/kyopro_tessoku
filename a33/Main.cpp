#include <iostream>
using namespace std;

int N, A[100009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  int nim = A[1];
  for (int i = 2; i <= N; i++) nim = nim ^ A[i];

  if (nim == 0) cout << "Second" << endl;
  else cout << "First" << endl;
  return 0;
}
