#include <iostream>
#include <set>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    set<pair<int,int>> s;

    if (m == 0) {
        cout << n << endl;
        return 0;
    }

    int a, b;
    cin >> a >> b;
    a--; // displace to start from position 0
    b--; // displace to start from position 0
    b += 1;
    a = a < 0 ? 0 : a;
    b = b > n ? n : b;

    int collapsed = 0;
    collapsed += b-a;
    // cout << "inserting a:" << a << " b:" << b << endl;
    s.insert(make_pair(a,b));
    // cout << "a:" << a << " b:" << b << " count:" << b-a << endl;
    cout << n - collapsed << endl;
    for (int i = 1; i < m; i++) {
        cin >> a >> b;
        a--; // displace to start from position 0
        b--; // displace to start from position 0
        b += 1;
        a = a < 0 ? 0 : a;
        b = b > n ? n : b;
        // cout << "inserting a:" << a << " b:" << b << endl;
        auto p = s.insert(make_pair(a,b));
        if (!p.second) {
            cout << n - collapsed << endl;
            continue;
        };
        auto it = p.first;

        int count = 0;
        count += b-a;

        while (it != prev(s.end())) {
            auto it_r = it;
            it_r++;
            int ar = (*it_r).first;
            int br = (*it_r).second;

            if (b < ar) {
                break;
            } else if (b <= br) {
                count -= b - ar;
                b = br;
                s.erase(it_r);
                it = s.erase(it);
                it = s.insert(it, make_pair(a,b));
                break;
            } else {
                auto tmp = it_r++;
                s.erase(tmp);
                count -= br-ar;
                it_r--;
                continue;
            }

        }
        while (it != s.begin()) {
            auto it_l = it;
            it_l--;
            int al = (*it_l).first;
            int bl = (*it_l).second;

            if (bl < a) {
                break;
            } else if (al <= a) {
                if (b <= bl) {
                    count -= b-a;
                    s.erase(it);
                    break;
                } else {
                    count -= bl-a;
                    a = al;
                    s.erase(it_l);
                    it = s.erase(it);
                    it = s.insert(it, make_pair(a,b));
                    break;
                }
            } else {
                auto tmp = it_l--;
                s.erase(tmp);
                count -= bl-al;
                continue;
            }
        }
        // cout << "a:" << a << " b:" << b << " count:" << count << endl;
        collapsed += count;

        cout << n - collapsed << endl;

        // for (auto &p : s) {
        //     cout << "[" << p.first << ", " << p.second << ") ";
        // }


    }
}
