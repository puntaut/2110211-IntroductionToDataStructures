#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool has_prev(map<int, int>::iterator it, map<int, int> &m) {
    return (it != m.begin());
}

int main() {
    int n,q;
    cin >> n >> q;

    map<int, int> ranges;
    int collapsed = 0;

    for (int i = 0; i < q; i++) {
        int a,b;
        cin >> a >> b;
        b += 1;
        a = max(a,1);
        b = min(b,n+1);

        int to_destroy = 0;

        if (ranges.empty()) {
            ranges[a] = b;
            collapsed += b-a;
        } else {
            auto it = ranges.lower_bound(a);
            if (has_prev(it, ranges)) {
                auto prev_it = prev(it);
                if (a <= prev_it->second) {
                    a = min(a, prev_it->first);
                    b = max(b, prev_it->second);
                    to_destroy -= prev_it->second - prev_it->first;
                    ranges.erase(prev_it);
                }
            }
            while (it != ranges.end()) {
                if (b >= it->first) {
                    b = max(b, it->second);
                    // cout << "B = " << b << endl;
                    to_destroy -= it->second - it->first;
                    auto tmp = it++;
                    ranges.erase(tmp);
                } else {
                    break;
                }
            }
            ranges[a] = b;
            to_destroy += b - a;
            collapsed += to_destroy;

        }
        // cout << "dog"<< endl;

        // for (auto p: ranges) {
        //     cout << "[" << p.first << " " << p.second << ") ";
        // }
        // cout << endl;
        cout << n - collapsed << endl;


    }
}