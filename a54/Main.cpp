#include <iostream>
#include <map>
using namespace std;

int Q;

int main() {
  cin >> Q;
  
  map<string, int> m; 
  for (int i = 1; i <= Q; i++) {
    int type;
    string name;
    cin >> type >> name;

    if (type == 1) {
      int score;
      cin >> score;
      m[name] = score;
    } else {
      cout << m[name] << endl;
    }
  }

  return 0;
}
