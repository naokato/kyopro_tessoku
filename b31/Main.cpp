#include <iostream>
using namespace std;

long long N;

int main() {
  cin >> N;

  long long answer = N/3 + N/5 + N/7 - N/15 - N/21 - N /35 + N/105;
  cout << answer << endl;
  return 0;
}
