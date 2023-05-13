#include <iostream>
using namespace std;

int N;
int P[109][109];

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) cin >> P[i][j];

  int rows[109];
  int columns[109];
  for (int i = 1; i <= N; i++) {
    rows[i] = 0;
    for (int j = 1; j <= N; j++) rows[i] += P[i][j];
  }
  for (int j = 1; j <= N; j++) {
    columns[j] = 0;
    for (int i = 1; i <= N; i++) columns[j]  += P[i][j];
  }
  
  int Answer = 0;
  for (int i = 1; i <= N - 1; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (rows[i] > rows[j]) Answer += 1; 
      if (columns[i] > columns[j]) Answer += 1; 
    }
  }

  cout << Answer << endl;

  return 0;
}
