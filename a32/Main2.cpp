#include <iostream>
using namespace std;

int N, A, B;

int main() {
  cin >> N >> A >> B;

  int sum = A + B;

  // 最後相手に 0 <= n < A で渡せれば勝ち 
  // すなわち、今現在、下記の状態のいずれかであれば勝てる
  // A <= n < 2A
  // B <= n < A + B = sum
  // 相手の選択に対して逆の選択をする事で、必ず sum だけ減らせるから、
  // A + sum * m <= n < 2A + sum * m
  // A <= n % sum < 2A
  // B + sum * m <= n < sum + sum * m
  // B <= n % sum

  // 逆に、
  // N % sum < A
  // の時、
  // N = sum * M + X (0 <= X < A)
  // N - A = sum * M + (X - A)
  //       = sum * (M - 1) + (sum - A + X)
  //       = sum * (M - 1) + (B + X)
  // (N - A) % sum = B + X >= B > A
  //
  // N - B = sum * M + (X - B)
  //       = sum * (M - 1) + (sum - B + X)
  //       = sum * (M - 1) + (A + X)
  // A + X < A + B = sum より
  // (N - B) % sum = A + X > A

  if ((N % sum) >= A && (N % sum) < 2 * A) cout << "First";
  else cout << "Second";
  return 0;
}
