#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, D, X[200009], Y[200009];
bool worked[200009];

struct job {
  int startDay;
  int income;
};

bool operator<(const job& lhs, const job& rhs) {
  if (lhs.income < rhs.income) return true;
  else if (lhs.income == rhs.income && lhs.startDay > rhs.startDay) return true;
  return false;
}

int main() {
  cin >> N >> D;
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
  for (int i = 1; i <= N; i++) worked[i] = false;

  priority_queue<job> q;
  for (int i = 1; i <= N; i++) {
    job j;
    j.startDay = X[i];
    j.income = Y[i];
    q.push(j);
  }

  int answer = 0;
  while (!q.empty()) {
    job j = q.top();
    q.pop();
    if (worked[j.startDay] == false) {
      worked[j.startDay] = true;
      answer += j.income;
    }
    cout << j.startDay << " " << j.income << endl;
  }

  cout << answer << endl;
  return 0;
}
