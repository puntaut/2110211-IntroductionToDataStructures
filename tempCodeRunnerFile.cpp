#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void insert_range(set<pair<int, int>> &setOfRange, pair<int, int> data) {
    int a = data.first;
    int b = data.second;

    auto p = setOfRange.insert(data);
    auto it = p.first;
    auto it_r = p.first;
    auto it_l = make_reverse_iterator(p.first);

    ++it_r;
    while (it_r != setOfRange.end()) {
        int ar = (*it_r).first;
        int br = (*it_r).second;
        if (b < ar) {
            break;
        } else if (b <= br) {
            // (*it).second = br;
            auto tmp = it;
            auto hint_it = setOfRange.erase(tmp);
            b = br;
            it = setOfRange.insert(hint_it, make_pair(a,b));
            tmp = it_r++;
            setOfRange.erase(tmp);
            break;
        } else {
            auto tmp = it_r++;
            setOfRange.erase(tmp);
        }
    }



    // ++it_l;
    // while (it_l != (setOfRange.rend())) {
    //     int al = (*it_l).first;
    //     int bl = (*it_l).second;
    //     if (bl < a) {
    //         break;
    //     } else if (al <= a) {
    //         // (*it).second = br;
    //         auto tmp = it;
    //         auto hint_it = setOfRange.erase(tmp);
    //         a = al;
    //         it = setOfRange.insert(hint_it, make_pair(a,b));
    //         setOfRange.erase(it_l.base());
    //         break;
    //     } else {
    //         auto tmp = it_l++;
    //         setOfRange.erase(tmp.base());
    //     }
    // }

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
        }
    }
}