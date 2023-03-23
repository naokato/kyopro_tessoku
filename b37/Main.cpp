#include <iostream>
#include <cmath>
using namespace std;

long long N;
long long sum[10];

long long power(long long i) {
  return (long long) pow(10, i);
}

int main() {
  cin >> N;

  sum[0] = 0LL;
  for (long long i = 1; i < 10; i++) {
    sum[i] = sum[i - 1] + i;
  }
  
  long long answer = 0LL;
  for (long long i = 0; i <= 14; i++) {
    long long fullCount = N / power(i + 1);
    long long reminderAtI = N % power(i);
    long long reminderAtIKeta = (N / power(i)) % 10LL;
    answer += fullCount * power(i) * sum[9];
    if (reminderAtIKeta >= 2) answer += sum[reminderAtIKeta - 1] * power(i);
    answer += (reminderAtI + 1) * reminderAtIKeta;
  }

  cout << answer << endl;
  return 0;
}
