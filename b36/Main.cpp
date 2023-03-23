#include <iostream>
using namespace std;

int N, K;
char S[300009];

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> S[i];

  int onCount = 0;
  for (int i = 1; i <= N; i++) {
    if (S[i] == '1') onCount++;
  }

  // 操作によって ON 状態の偶奇性は変化しないため、
  // 現在の ON の数と K の偶奇性が一致しなければ条件を満たさない
  // 逆に偶奇性が一致するなら、一度に2つずつ数を増減出来るので、
  // 必ず K に辿り着く
  if ((onCount % 2) == (K % 2)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;

}
