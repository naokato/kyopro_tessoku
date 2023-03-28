#include <iostream>
using namespace std;

int N, M, A[200009];
int incorrect[200009];

int main() {
  cin >>N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i];
 
  
  for (int i = 1; i <= M; i++) {
    incorrect[A[i]]++;
  }

  // answer
  for (int i = 1; i <= N; i++) cout << M - incorrect[i] << endl;
  return 0;
}
