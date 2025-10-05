#include <iostream>
#include <vector> 
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> type2power(n, 1);
    vector<int> v(n);
    map<int, int> power2count;

    power2count[1] = m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        int old_power = type2power[type];
        int new_power = v[i];
        if (new_power > old_power) {
            power2count[old_power]--;
            if (power2count[old_power] == 0) power2count.erase(old_power);
            type2power[type] = new_power;
            power2count[new_power]++;
        }

        // cout << "power2count: ";
        // for (auto x : power2count) {
        //     cout << x << " ";
        // }

        auto it = power2count.begin();
        cout << it->first << " ";
    }
    cout << endl;
}