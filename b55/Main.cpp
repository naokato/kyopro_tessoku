#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int Q;

int main() {
  cin >> Q;

  set<long long> s;
  for (int i = 1; i <= Q; i++) {
    int type;
    long long value;
    cin >> type >> value;
    if (type == 1) {
      s.insert(value);
    } else {
      if (s.empty()) {
        cout << -1 << endl;
        continue;
      }

      auto itr = s.lower_bound(value);
      if (itr == s.end()) {
        itr--;
        cout << abs(value - (*itr)) << endl;
        continue;
      }

      if (itr == s.begin()) {
        cout << abs(value - (*itr)) << endl;
        continue;
      }
      
      int bigger = *itr;
      int smaller = *(--itr);
      cout << min(abs(value - smaller), abs(value - bigger)) << endl;
    }
  }

  return 0;
}
