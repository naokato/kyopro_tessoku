#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int Q;

int main() {
  cin >> Q;

  set<int> s;
  for (int i = 1; i <= Q; i++) {
    int type, value;
    cin >> type >> value;

    if (type == 1) {
      s.insert(value);
    } else if (type == 2) {
      s.erase(value);
    } else {
      auto itr = s.lower_bound(value);
      if (itr == s.end()) cout << -1 << endl;
      else cout << (*itr) << endl;
    }
  }

  return 0;
}
