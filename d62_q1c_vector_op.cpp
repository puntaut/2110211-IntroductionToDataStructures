#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool gth (int a,int b) {
    return a > b;
}

int main() {
    int n;
    string op;
    vector<int> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "pb") {
            int x;
            cin >> x;
            v.push_back(x);
        } else if (op == "sa") {
            sort(v.begin(), v.end());
        } else if (op == "sd") {
            sort(v.begin(), v.end(), gth);
        } else if (op == "r") {
            reverse(v.begin(), v.end());
        } else if (op == "d") {
            int x;
            cin >> x;
            v.erase(v.begin() + x);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;

    return 0;
}