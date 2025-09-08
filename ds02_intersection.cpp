#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> v1;
    vector<int> v2;
    while (n--) {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    while (m--) {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    auto it1 = v1.begin();
    auto it2 = v2.begin();

    int tmp;
    bool hastmp = false;

    while (it1 != v1.end() && it2 != v2.end()) {
        if (*it1 == *it2) {
            if (!hastmp) {
                cout << *it1 << " ";
                tmp = *it1;
                hastmp = true;
            } else if (*it1 != tmp) {
                tmp = *it1;
                cout << *it1 << " ";
            }
            it1++;
            it2++;
        } else if (*it1 < *it2) {
            it1++;
        } else {
            it2++;
        }
    }
    cout << endl;
}