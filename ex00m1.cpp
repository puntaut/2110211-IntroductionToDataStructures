#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

auto cmp = [] (const pair<int, int> &a, const pair<int, int> &b) {
    return (b.first < a.first || (a.first == b.first && b.second < a.second));
};

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> chefs(cmp);

    bool finished = false;

    int global_t = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        chefs.push(make_pair(global_t, x));
    }

    while (m != 0) {
        if (global_t == chefs.top().first) {
            auto chef = chefs.top();
            chef.first += chef.second;
            chefs.pop();
            chefs.push(chef);
            cout << 0 << endl;
            m--;
        } else {
            auto chef = chefs.top();
            int d = chef.first - global_t;
            chef.first += chef.second;
            chefs.pop();
            chefs.push(chef);
            cout << d << endl;
            m--;
        }
    }
}