#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> y;
    int n;
    cin >> n;
    bool found = false;
    for (int i = 0; i < n; i++) {
        int yi;
        cin >> yi;
        auto p = y.insert(yi);
        if (yi > n || yi < 1 || p.second == false) {
            cout << "NO" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "YES" << endl;
    }
}