#include <iostream>
#include <vector>
using namespace std;

int X, Y, K, x[30], y[30];

int main() {
  cin >> X >> Y;

  vector<pair<int, int>> v;
  int currentX = X;
  int currentY = Y;

  while(currentX != 1 || currentY != 1) {
    v.emplace_back(currentX, currentY);
    if (currentX >= currentY) currentX = currentX - currentY;
    else currentY = currentY - currentX;
  }

  // answer
  cout << v.size() << endl;
  for(auto it = v.rbegin(); it != v.rend(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
  return 0;
}
