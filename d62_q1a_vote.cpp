#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<string> v;
    // map<string, int> m;
    vector<pair<string, int>> vp;
    v.resize(n);
    vp.reserve(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    auto it = v.begin();
    string check = *it;
    vp.push_back({*it, 1});
    if (n >= 2) {
        it++;
        while (it != v.end()) {
            if (*it == check) {
                (*(vp.end()-1)).second += 1;
            } else {
                vp.push_back({*it, 1});
                check = *it;
            }
            ++it;
        }
    }

    sort(vp.begin(), vp.end(), [] (const auto &a, const auto &b) {
        return a.second > b.second;
    });
    // for (auto &p : vp) {
    //     cout << "first: " << p.first << " || second: "<< p.second << endl;
    // }
    if (vp.size() < k) {
        // cout << "case1:";
        cout << (*(vp.end()-1)).second << endl; 
    } else {
        // cout << "case2:";
        cout << (*(vp.begin()+(k-1))).second << endl;
    }

    // ถ้าเลือกไปน้อยกว่า quota
    // if (n < k) {
        
    // } else {

    // }

}