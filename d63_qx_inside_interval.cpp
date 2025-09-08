#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector <pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());

    while (m--) {
        int x;
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), make_pair(0,x), [] (const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });
        if (it != v.end() && (*it).first <= x) {
            cout << "1" << " ";
        } else {
            cout << "0" << " ";
        }

    }
    cout << endl;
}