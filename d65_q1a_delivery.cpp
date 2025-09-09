#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> a_queue;
    queue<int> b_queue;
    vector<int> v;
    v.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }

    vector<int> revenue;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            if (a == 1) {
                a_queue.push(b);
            } else {
                b_queue.push(b);
            }
        } else if (op == 2) {
            int x;
            if (a_queue.empty()) {
                x = b_queue.front();
                b_queue.pop();
            } else if (b_queue.empty()) {
                x = a_queue.front();
                a_queue.pop();
            } else if (a_queue.front() <= b_queue.front()) {
                x = a_queue.front();
                a_queue.pop();
            } else {
                x = b_queue.front();
                b_queue.pop();
            }
            if (revenue.size() != 0) {
                x += *(revenue.end()-1);
            }
            revenue.push_back(x);
        }
    }

    // for (auto &x : revenue) {
    //     cout << x << " ";
    // }

    for (int i = 0; i < m; i++) {
        auto it = lower_bound(revenue.begin(), revenue.end() ,v[i]);
        if (it == revenue.end()) {
            cout << "-1 ";
        } else {
            cout << it - revenue.begin() + 1 << " ";
        }
    }
}