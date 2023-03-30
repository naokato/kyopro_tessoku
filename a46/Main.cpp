#define DEBUG 0
#include <iostream>
#include <cmath>
using namespace std;

int N, X[159], Y[159];
int answer[159];
bool visited[159];

double calcDistance(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

  // initialize
  for (int i = 1; i <= N; i++) visited[i] = false;
  answer[1] = 1;
  visited[1] = true;
  double totalDistance = 0;

  for (int i = 2; i <= N; i++) {
    int currentCity = answer[i - 1];
    double minDistance = 10000000;
    int minCity = 0;

    for (int j = 1; j <= N; j++) {
      if (visited[j]) continue;

      double distance = calcDistance(X[currentCity], Y[currentCity], X[j], Y[j]);
      if (minDistance > distance) {
        minDistance = distance;
        minCity = j;
      }
    }

    answer[i] = minCity;
    visited[minCity] = true;
    totalDistance += minDistance;
  }
  totalDistance += calcDistance(X[answer[N]], Y[answer[N]], X[1], Y[1]);

  #if DEBUG
  cout << totalDistance << endl;
  #endif

  for (int i = 1; i <= N; i++) {
    cout << answer[i] << endl;
  }
  cout << 1 << endl;
  return 0;
}
