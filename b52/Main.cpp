#include <iostream>
#include <queue>
using namespace std;

int N, X;
char A[100009];

int main() {
  cin >> N >> X; 
  for (int i = 1; i <= N; i++) cin >> A[i];

  queue<int> q;
  q.push(X);
  A[X] = '@';

  while (!q.empty()) {
    int pos = q.front();
    q.pop();
    if (pos - 1 >= 1 && A[pos - 1] == '.') {
      A[pos - 1] = '@';
      q.push(pos - 1);
    }
    if (pos + 1 <= N && A[pos + 1] == '.') {
      A[pos + 1] = '@';
      q.push(pos + 1);
    }
  }
  
  for (int i = 1; i <= N; i++) cout << A[i];
  return 0;
}
