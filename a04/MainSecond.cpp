#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
  cin >> N;

  vector<int> vec; 
  for (int i = 0; i <= 9; i++) {
    int wari = (1 << i);
    if ((N / wari) % 2 == 1) vec.push_back(1);
    else vec.push_back(0);
  }

  reverse(vec.begin(), vec.end());
  for (const int digit: vec) {
    cout << digit;
  }

  return 0;
}
