#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct gth {
    bool operator() (int a, int b) {
        return b < a;
    }
};

int main() {
    int n, w;
    cin >> n >> w;

    int width = w + 1;

    queue<pair<int, multiset<int>::iterator>> q;

    multiset<int> tmp;

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;

        auto it = tmp.insert(u);
        q.push(make_pair(u, it));

        if (tmp.size() == w+1) {
            int med = *next(tmp.begin(), w/2);
            tmp.erase(q.front().second);
            q.pop();
            // cout << "i: " << i << endl;
            cout << med << " ";
        }
    }
    cout << endl;

}