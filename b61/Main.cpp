#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];

  for (int i = 1; i <= M; i++) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  int maxFriends = 0;
  int influencer;
  for (int i = 1; i <= N; i++) {
    if (maxFriends < G[i].size()) {
      maxFriends = G[i].size();
      influencer = i;
    }
  }

  cout << influencer << endl;
  return 0; 
}
