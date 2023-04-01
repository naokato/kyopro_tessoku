#define DEBUG 0
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int N, X[159], Y[159];
int answer[159];
double score;

int RandInt(int a, int b) {
  return a + rand() % (b - a + 1);
}

double calcDistance(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double GetScore() {
  double distance = 0;
  for (int i = 1; i <= N; i++) {
    distance += calcDistance(X[answer[i]], Y[answer[i]], X[answer[i + 1]], Y[answer[i + 1]]);
  }
  return distance;
}


int main() {
  // input
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

  // initialize
  for (int i = 1; i <= N; i++) answer[i] = i;
  answer[N + 1] = 1;

  score = GetScore();
  for (int i = 1; i <= 200000; i++) {
    int L = RandInt(2, N);
    int R = RandInt(2, N);
    if (L > R) swap(L, R);

    reverse(answer + L, answer + R + 1);
    double currentScore = GetScore();
    if (score >= currentScore) {
      score = currentScore;
    } else {
      // if the score is not good, undo reverse
      reverse(answer + L, answer + R + 1);
    }
  }

  #if DEBUG
  cout << score << endl;
  #endif

  for (int i = 1; i <= N + 1; i++) {
    cout << answer[i] << endl;
  }

  return 0;
}
