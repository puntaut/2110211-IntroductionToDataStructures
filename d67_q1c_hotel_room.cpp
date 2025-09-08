#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, set<int>> cap2floor;
    map<int, int> floor2count;
    int hotel_cap = 0;
    for (int i = 0; i < n; i++) {
        int room_i;
        cin >> room_i;
        cap2floor[room_i].insert(i);
        hotel_cap += room_i;
    }
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        if (hotel_cap >= p) {
            while (p > 0) {
                int pi;
                auto it = cap2floor.lower_bound(p);
                if (it != cap2floor.end()) {
                    pi = p;
                    int floor = *prev((it->second).end());
                    int old_cap = it->first;
                    int new_cap = old_cap - pi;
                    cap2floor[old_cap].erase(floor);
                    if (cap2floor[old_cap].empty()) {
                        cap2floor.erase(old_cap);
                    }
                    cap2floor[new_cap].insert(floor);
                    floor2count[floor] += pi;
                    hotel_cap -= pi;
                    p = 0;
                } else {
                    it = prev(cap2floor.end());
                    pi = it->first;
                    int floor = *prev((it->second).end());
                    cap2floor[pi].erase(floor);
                    if (cap2floor[pi].empty()) {
                        cap2floor.erase(pi);
                    }
                    floor2count[floor] += pi;
                    p -= pi;
                    hotel_cap -= pi;
                }

            }
            for (auto kv : floor2count) {
                
                // if (kv != *prev(floor2count.end())) {
                cout << (kv.first+1) << " " << kv.second << " ";
                // }
            }
            floor2count.clear();
            cout << "\n";
        } else {
            cout << "-1" << "\n";
        }
    }
}