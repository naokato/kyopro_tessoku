#include <iostream>
using namespace std;

int N, H, W;
int A[100009], B[100009];

int main() {
  cin >> N >> H >> W;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];

  int nim = A[1] - 1;
  for (int i = 2; i <= N; i++) nim = nim ^ (A[i] - 1);
  for (int i = 1; i <= N; i++) nim = nim ^ (B[i] - 1);

  if (nim == 0) cout << "Second" << endl;
  else cout << "First" << endl;
  return 0;
}
