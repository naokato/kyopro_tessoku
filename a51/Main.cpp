#include <iostream>
#include <stack>
using namespace std;

int Q;

int main() {
  cin >> Q;

  stack<string> S;

  for (int i = 1; i <= Q; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      string x;
      cin >> x;
      S.push(x);
    } else if (type == 2) {
      cout << S.top() << endl;
    } else {
      S.pop();
    }
  }

  return 0;
}
