#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int wall_length,q;
    cin >> wall_length >> q;

    vector<pair<int, int>> t2range(q);

    for (int i = 0; i < 2*q; i++) {
        int pos, t, d;
        cin >> pos >> t >> d;
        if (d == 0) {
            t2range[t - 1].first = pos;
        } else {
            t2range[t - 1].second = pos;
        }
    }

    set<pair<int, int>> s;

    for (auto it = t2range.begin(); it != t2range.end(); ++it) {
        if (it == t2range.begin()) {
            int a = it->first;
            int b = it->second;
            s.insert(make_pair(a, 0));
            s.insert(make_pair(b, 1));
        } else {
            int a = it->first;
            int b = it->second;
            auto ita = s.lower_bound(make_pair(a, -1));
            auto itb = s.lower_bound(make_pair(b, -1));
            if (ita == itb && a != ita->first && b != itb->first) {
                s.insert(make_pair(a, 0));
                s.insert(make_pair(b, 1));
            } else {
                continue;
            }

        }
    }

    int layer_count = 0;
    int top_record = 0;
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (it->second == 0) {
            layer_count += 1;
            top_record = max(top_record, layer_count);
        } else {
            layer_count -= 1;
        }
    }
    cout << top_record << endl;
    if (layer_count != 0) cout << "WTF" << endl;
}