#include <iostream>
using namespace std;

int N, K;

int main() {
  cin >> N >> K;

  // 最低でも右に N - 1、下に N - 1移動する必要があり (total: 2N - 2)、
  // もし戻る方向に進んだ場合には、同じ数だけ進み直す必要がある、
  // したがって、K は偶数でなければ鳴らない
  if ((K % 2 == 0) && (K >= 2 * (N - 1))) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
