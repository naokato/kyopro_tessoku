#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int Q;

int main() {
  cin >> Q;

  priority_queue<int, vector<int>, greater<int>> q; 
  for (int i = 1; i <= Q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int price;
      cin >> price;
      q.push(price);
    } else if (type == 2) {
      cout << q.top() << endl;
    } else {
      q.pop();
    }
  }

  return 0;
}
