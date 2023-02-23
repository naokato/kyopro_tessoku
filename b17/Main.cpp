#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int H[100009];
long long DP[100009];
vector<int>answer;

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> H[i];

  DP[1] = 0;
  DP[2] = abs(H[1] - H[2]);
  for (int i = 3; i <= N; i++) {
    DP[i] =  min(
      DP[i - 2] + abs(H[i] - H[i - 2]),
      DP[i - 1] + abs(H[i] - H[i - 1])
    );
  }

  int i = N;
  while(true) {
    answer.push_back(i);
    if (i == 1) break;
    if (DP[i] == DP[i - 1] + abs(H[i] - H[i - 1])) i = i - 1;
    else i = i - 2;
  }
  reverse(answer.begin(), answer.end());

  // answer
  cout << answer.size() << endl;
  for (int i = 0; i < answer.size(); i++) {
    if (i >= 1) cout << " ";
    cout << answer[i];
  }

  return 0;
}
