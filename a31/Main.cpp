#include <iostream>
using namespace std;

long long N;

int main() {
  cin >> N;

  long long answer = N/3 + N/5 - N/15;
  cout << answer << endl;
  return 0;
}
