#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        v[i] = {t, d};
    }
    sort(v.begin(), v.end());
    if (v.size() > 1) {
        for (int i = 1; i < n; i++) {
            int x = v[i-1].second + v[i].second;
            if (x >= k) {
                for (int j = i; j < n; j++) {
                    v[j].second = k;
                }
                break;
            }
            v[i].second = x;
        }
    }

    // for (auto &p : v) {
    //     cout << "first:" << p.first << " second:" << p.second << endl;
    // }

    while(m--) {
        int a, q;
        cin >> a >> q;
        if (a == 1) {
            auto it = upper_bound(v.begin(), v.end(), make_pair(q, 0), [] (const pair<int, int> &a, const pair<int, int> &b) {
                return a.first < b.first;
            });
            if (it == v.begin()) {
                cout << k << endl;
            } else {
                cout << k - (*prev(it)).second << endl;
            }
        } else if (a == 2) {
            if (k-q < 0) {
                cout << "0" << endl;
                continue;
            }
            auto it = upper_bound(v.begin(), v.end(), make_pair(0, k-q), [] (const pair<int, int> &a, const pair<int, int> &b) {
                return a.second < b.second;
            });
            // cout << "d:" << k-q << endl;
            cout << (*it).first << endl;
        }
    }

}