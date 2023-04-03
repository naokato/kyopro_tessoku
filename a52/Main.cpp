#include <iostream>
#include <queue>
using namespace std;

int Q;

int main() {
  cin >> Q;

  queue<string> q;
  for (int i = 1; i <= Q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      string name;
      cin >> name;
      q.push(name);
    } else if (type == 2) {
      cout << q.front() << endl;
    } else {
      q.pop();
    }
  }

  return 0;
}
