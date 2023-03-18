#include <iostream>
using namespace std;

// fixed
// X = 2
// Y = 3
int N, X, Y;
long long A[100009];
int grundyForA[100009];

int main() {
  cin >> N >> X >> Y;
  for (int i = 1; i <= N; i++) cin >> A[i];

  for (int i = 1; i <= N; i++) {
    int remainder = A[i] % 5;
    switch(remainder) {
      case 0:
      case 1:
        grundyForA[i] = 0;
        break;
      case 2:
      case 3:
        grundyForA[i] = 1;
        break;
      case 4:
        grundyForA[i] = 2;
        break;
    }
    // cout << remainder << ":" << grundyForA[i] << endl;
  }
  

  int xorsum = 0;
  for (int i = 1; i <= N; i++) xorsum = xorsum ^ grundyForA[i];

  if (xorsum == 0) cout << "Second" << endl;
  else cout << "First" << endl;
  return 0;
}
