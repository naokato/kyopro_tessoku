#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string S;

int main() {
  cin >> S;
  int len = S.length();

  vector<pair<int, int>> answers;
  stack<int> bracketStack;
  for (int i = 1; i <= len; i++) {
    if (S[i - 1] == '(') {
      bracketStack.push(i);
    } else {
      answers.emplace_back(bracketStack.top(), i);
      bracketStack.pop();
    }
  }

  for (const auto& answer: answers) {
    cout << answer.first << " " << answer.second << endl;
  }

  return 0;
}
