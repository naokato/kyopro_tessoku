#include <iostream>
using namespace std;

long long a, b, c;

int main() {
  cin >> a >> b >> c;
  
  long long total = a + b + c;
  if (total == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
