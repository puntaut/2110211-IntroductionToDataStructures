#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        int year, month;
        cin >> year >> month;
        v[i] = year*100 + month;

    }
    sort(v.begin(), v.end());

    while (m--) {
        int wh_year, wh_month;
        cin >> wh_year >> wh_month;
        int wh_ym = wh_year*100 + wh_month;
        auto it = lower_bound(v.begin(), v.end(), wh_ym);
        if (wh_ym < *(v.begin())) {
            cout << "-1 -1 ";
        } else if (it != v.end() && wh_ym == *it) {
            cout << "0 0 ";
        } else {
            int ans_year = (*prev(it))/100;
            int ans_month = (*prev(it))%100;
            cout << ans_year << " " << ans_month << " ";
        }
    }
    cout << endl;

}