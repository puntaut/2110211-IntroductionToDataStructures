#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> lhs;
    vector<int> rhs;
    set<pair<int, int>> intervals;
    lhs.resize(m);
    rhs.resize(m);


    for (int i = 0; i < 2*m; i++) {
        int x, c, d;
        cin >> x >> c >> d;
        int idx = c-1;
        if (d == 0) {
            lhs[idx] = x;
        } else {
            rhs[idx] = x;
        }
    }

    intervals.insert(make_pair(lhs[0], 0));
    intervals.insert(make_pair(rhs[0], 1));
    for (int i = 1; i < m; i++) {
        // for (int i = 0; i < intervals.size(); i++) {
            // cout << "i=" << i << ": " << intervals[i].first << " " << intervals[i].second << endl;
        // }
        auto it1 = intervals.lower_bound(make_pair(lhs[i], -1));
        auto it2 = intervals.lower_bound(make_pair(rhs[i], -1));
        // cout << "lhs:" << lhs[i] << " rhs:" << rhs[i] << endl;
        // cout << "it1:" << (*it1).first << " it2:" << (*it2).first << endl;
        if (it1 != it2) continue;
        if ((*it1).first == lhs[i] || (*it1).first == rhs[i]) continue; 
        if ((*it2).first == lhs[i] || (*it2).first == rhs[i]) continue;
        intervals.insert(it1, make_pair(lhs[i], 0));
        intervals.insert(it2,make_pair(rhs[i], 1));
        // cout << "inserted: [" << lhs[i] << ", " << rhs[i] << "]" << endl;
    }
    int max = 0;
    int x = 0;
    for (auto &p : intervals) {
        // cout <<intervals[i].first << " " << intervals[i].second << endl;
        if (p.second == 0) {
            x++;
            if (x > max) {
                max = x;
            }
        } else {
            x--;
        }
    }
    cout << max << endl;
}