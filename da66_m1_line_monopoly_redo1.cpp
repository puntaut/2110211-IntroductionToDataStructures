#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool has_prev(map<int, int>::iterator &it, map<int, int> &m) {
    return it != m.begin();
}

bool has_next(map<int, int>::iterator &it, map<int, int> &m) {
    return it != prev(m.end());
}
int main() {
    int n;
    cin >> n;

    map<int, int> ranges; 

    for (int i = 0; i < n; i++) {   
        int type;
        cin >> type;
        if (type == 1) {
            int a,b;
            cin >> a >> b;
            b += 1;
            if (ranges.empty())  {
                ranges[a] = b;
            } else {
                auto it = ranges.lower_bound(a);
                if (has_prev(it, ranges)) {
                    auto prev_it = prev(it);
                    if (a <= prev_it->second) {
                        a = min(a, prev_it->first);
                        b = max(b, prev_it->second);
                        ranges.erase(prev_it);
                    }
                }
                while (it != ranges.end()) { 
                    if (b >= it->first) {
                        b = max(b, it->second);
                        auto tmp = it++;
                        ranges.erase(tmp);
                    } else {
                        break;
                    }
                }
                ranges[a] = b;
            }
        } else {
            cout << ranges.size() << endl;
            // for (auto p : ranges) {
            //     cout << "[" << p.first << ", " << p.second << ") ";
            // }
            // cout << endl;
        }
    }
}