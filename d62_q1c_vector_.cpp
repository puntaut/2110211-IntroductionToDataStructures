#include <iostream>
#include <set>

using namespace std;

void print(set<int> &s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m >> n;
    set<int> set1;
    set<int> set2;
    while (m--) {
        int x;
        cin >> x;
        set1.insert(x);
    }
    while (n--) {
        int x;
        cin >> x;
        if (set1.find(x) != set1.end()) {
            set2.insert(x);
        }
    }
    print(set2);
}