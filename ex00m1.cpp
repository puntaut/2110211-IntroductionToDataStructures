#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

auto cmp = [] (const pair<int, int> &a, const pair<int, int> &b) {
    return (b.first < a.first || (a.first == b.first && b.second < a.second));
};

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> chefs(cmp);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        chefs.push(make_pair(0, x));
    }

    while (m != 0) {
        auto chef = chefs.top();
        int d = chef.first;
        chef.first += chef.second;
        chefs.pop();
        chefs.push(chef);
        cout << d << endl;
        m--;
    }
}