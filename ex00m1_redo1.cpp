#include <iostream>
#include <queue>

using namespace std;

struct chef_compare {
    bool operator() (pair<int, int> &a, pair<int, int> &b) {
        return b.first < a.first || (a.first == b.first && b.second < a.second);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, chef_compare> chefs;

    // int time = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        chefs.push(make_pair(0, t));
    }

    for (int i = 0; i < m; i++) {
        auto chef = chefs.top();
        cout << chef.first << endl;
        chef.first += chef.second;
        chefs.pop();
        chefs.push(chef);
    }
}