#include <iostream>
#include <map>
#include <set>

using namespace std;

int main () {
    map<int, set<int>> count2floors;
    map<int, int> floor2count;

    int n, m;
    int sum = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        // adding data
        floor2count[i] = x;
        count2floors[x].insert(i);
        sum += x;
    }

    map<int, int> floor2count_sol;

    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;

        bool accept = true;

        // doing till p is 0
        if (sum >= p) {
            while (p != 0) {
                auto it = count2floors.lower_bound(p);
                if (it != count2floors.end()) {
                    auto it2del = prev((it->second).end());
                    int floor = *it2del;

                    // needed data
                    int prev_val = floor2count[floor];
                    int new_val = prev_val - p;

                    // deleting data
                    sum -= p;
                    floor2count[floor] -= p;
                    count2floors[prev_val].erase(it2del);
                    if (count2floors[prev_val].size() == 0) count2floors.erase(prev_val);
                    // adding new data
                    count2floors[new_val].insert(floor);
                    floor2count_sol[floor] += p;

                    // reseting p
                    p = 0;
                } else {
                    auto it = prev(count2floors.end());

                    auto it2del = prev((it->second).end());
                    int floor = *it2del;

                    // needed data
                    int k = it->first;

                    //removing data
                    p -= k;
                    sum -= k;
                    floor2count[floor] = 0;
                    (it->second).erase(it2del);
                    if ((it->second).size() == 0) count2floors.erase(it);

                    // adding data
                    floor2count_sol[floor] += k;
                }

            }
            for (auto kv : floor2count_sol) {
                cout << kv.first + 1 << " " << kv.second << " ";
            }
            cout << "\n";;

            floor2count_sol.clear();
        } else {
            cout << "-1" << "\n";
        }
    }
}
