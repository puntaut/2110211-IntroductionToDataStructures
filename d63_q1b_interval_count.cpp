#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m, k;


    cin >> n >> m >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    while (m--) {
        int p;
        cin >> p;
        auto it1 = lower_bound(v.begin(), v.end(), p-k);
        auto it2 = upper_bound(it1, v.end(), p+k);
        cout << it2-it1 << " ";
    }
    cout << endl;


}