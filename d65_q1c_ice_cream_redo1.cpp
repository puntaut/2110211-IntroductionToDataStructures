#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;
    vector<int> day2money(100001);

    day2money[0] = start;

    for (int i = 0; i < n; i++) {
        int a,s;
        cin >> a >> s;
        day2money[a] = s;
    }

    int add;
    int money = 0;
    for (int i = 0; i < 100001; i++) {
        if (day2money[i] != 0) add = day2money[i];
        money += add;
        day2money[i] = money;
    }

    for (int i = 0; i < m; i++) {
        int P,x;
        cin >> P >> x;

        if (day2money[x] >= P) {
            auto it = lower_bound(day2money.begin(), day2money.begin()+x+1, P);
            cout << it - day2money.begin() << " ";
        } else {
            auto it = lower_bound(day2money.begin()+x, day2money.end(), P+day2money[x]);
            cout << it - day2money.begin() << " ";
        }
    }
    cout << endl;

}