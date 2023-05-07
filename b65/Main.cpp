#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, T, A[100009], B[100009];
vector<int> G[100009];
vector<int> Child[100009];
bool used[100009];
int dist[100009];

void createChildAndDist(int current, int currentDist) {
  dist[current] = currentDist;
  for (const auto& node: G[current]) {
    if (!used[node]) {
      used[node] = true;
      Child[current].push_back(node);
      createChildAndDist(node, currentDist + 1);
    }
  }
  // cout << "creating Child... current=" << current << "/child size=" << Child[current].size() << endl;
}

int main() {
  cin >> N >> T;
  for (int i = 1; i <= N - 1; i++) cin >> A[i] >> B[i];
  
  // make non directed graph
  for (int i = 1; i <= N - 1; i++) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  
  for (int i = 1; i <= N; i++) dist[i] = -1;

  // create directed graph and calculate distance from T
  used[T] = true;
  createChildAndDist(T, 0);
  // for (int i = 1; i <= N; i++) {
  //   cout << "created Child: i=" << i << "/child size=" << Child[i].size() << endl;
  // }

  // sort by distance
  priority_queue<tuple<int, int, vector<int>>> PQ;
  for (int i = 1; i <= N; i++) PQ.push(make_tuple(dist[i], i, Child[i]));

  // calculate rank in the order of distance (far is first)
  int Answer[100009];
  while(!PQ.empty()) {
    const int currentDist = get<0>(PQ.top());
    const int current = get<1>(PQ.top());
    vector<int> children = get<2>(PQ.top());
    PQ.pop();

    // cout << "current=" << current << "/currentDist=" << currentDist << "/size of children=" << children.size() << endl;
    
    if (children.empty()) {
      Answer[current] = 0;
      continue;
    }

    int rank = 0;
    for (const auto& node: children) {
      rank = max(rank, Answer[node]);
    }
    Answer[current] = rank + 1;
  }

  for (int i = 1; i <= N; i++) {
    if (i != 1 ) cout << " ";
    cout << Answer[i];
  }

  return 0;
}
