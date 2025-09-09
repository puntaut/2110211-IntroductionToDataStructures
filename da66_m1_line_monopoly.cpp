#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void insert_range(set<pair<int, int>> &setOfRange, pair<int, int> data) {
    int a = data.first;
    int b = data.second;

    auto p = setOfRange.insert(data);
    if (!p.second) return;
    auto it = p.first;

    if (setOfRange.size() == 1) {
        ;
    } else {
        // right-side
        while (it != prev(setOfRange.end())) {
            auto it_r = it;
            ++it_r;
            int ar = (*it_r).first;
            int br = (*it_r).second;
            if (b < ar) {
                break;
            } else if (b <= br) {
                b = br;
                // cout << "right_erased: <" << (*it).first << ", " << (*it).second << ">" << endl;
                setOfRange.erase(it_r); // บรรทัดนี้ถ้าสลับกับบรรทัดล่างจะ segmentation fault
                it = setOfRange.erase(it);
                it = setOfRange.insert(it, make_pair(a,b));
                break;
            } else {
                it_r = setOfRange.erase(it_r);
                --it_r; // to the left of erased element
                continue;
            }
        }

        while (it != setOfRange.begin()) {
            auto it_l = it;
            --it_l;
            int al = (*it_l).first;
            int bl = (*it_l).second;
            if (bl < a) {
                break;
            } else if (al <= a) {
                a = al;
                // cout << "left_erased: <" << (*it).first << ", " << (*it).second << ">" << endl;
                setOfRange.erase(it_l); // บรรทัดนี้ถ้าสลับกับบรรทัดล่างจะ segmentation fault
                it = setOfRange.erase(it);
                it = setOfRange.insert(it, make_pair(a,b));
                break;
            } else {
                it_l = setOfRange.erase(it_l);
                continue;
            }
        }

    }


}

int main() {
    int n;

    cin >> n;

    set<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        int a, b;
        if (op == 1) {
            cin >> a >> b;
            b += 1;
            insert_range(s, make_pair(a,b));
        } else if (op == 2) {
            cout << s.size() << endl;
            // for (auto &p : s) {
            //     cout << "<" << p.first << ", " << p.second << ">" << endl;
            // }
        }
    }
}