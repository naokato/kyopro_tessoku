#include <iostream>
using namespace std;

int N;

int main() {
  cin >> N;
  
  for (int i = 9; i >= 0; i--) {
    int n = N / (1 << i);
    cout << n % 2;
  }

  return 0;
}
