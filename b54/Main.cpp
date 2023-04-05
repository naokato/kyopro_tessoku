#include <iostream>
#include <map>
using namespace std;

int N, A[100009];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];

  map<int, int> m;
  long long answer = 0LL;
  for (int i = 1; i <= N; i++) {
    answer += m[A[i]];
    m[A[i]] += 1;
  }

  cout << answer << endl;
  return 0;
}
