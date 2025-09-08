#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  map<int, set<int>> floors;
  int avaliable = 0;
  for (int i = 1; i <= N; i++) {
    int cap;
    cin >> cap;
    avaliable += cap;
    floors[cap].insert(i);
  }
  vector<int> reserve;
  while (M-- > 0) {
    int k;
    cin >> k;
    reserve.push_back(k);
  }
  for (int &r : reserve) {
    if (avaliable < r) {
      cout << "-1" << "\n";
    } else {
      map<int, int> declare;
      while (r > 0) {
        auto it = floors.lower_bound(r);
        if (it != floors.end()) {
          int cap = it->first;
          int floor = *prev(it->second.end());
          avaliable -= r;
          floors[cap].erase(floor);
          if (floors[cap].empty()) {
            floors.erase(cap);
          }
          if (cap - r > 0) {
            floors[cap - r].insert(floor);
          }
          declare[floor] = r;
          r = 0;
        } else {
          int cap = prev(floors.end())->first;
          int floor = *prev((prev(floors.end())->second).end());
          avaliable -= cap;
          floors[cap].erase(floor);
          if (floors[cap].empty()) {
            floors.erase(cap);
          }
          if (cap - r > 0) {
            floors[cap - r].insert(floor);
          }
          declare[floor] = cap;
          r -= cap;
        }
      }
      for (pair<int, int> e : declare) {
        cout << e.first << " " << e.second << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}