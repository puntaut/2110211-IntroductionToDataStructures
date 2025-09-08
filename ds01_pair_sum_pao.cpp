#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool pair_sum(vector<int> &A, map<int, int> &m, int &sum) {
  for (int &i : A) {
    int target = sum - i;
    if (target == i && m[target] >= 2) {
      return true;
    } else if (target != i && m[target] >= 1) {
      return true;
    }
  }
  return false;
}

int main() {
  int N, M, val, sum;
  cin >> N >> M;
  vector<int> A;
  while (N-- > 0) {
    cin >> val;
    A.push_back(val);
  }
  map<int, int> m;
  for (int &i : A) {
    m[i]++;
  }
  while (M-- > 0) {
    cin >> sum;
    bool isFound = pair_sum(A, m, sum);
    cout << ((isFound) ? "YES" : "NO") << endl;
  }
  return 0;
}