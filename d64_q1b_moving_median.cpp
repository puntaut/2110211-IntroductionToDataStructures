#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int n, w;
queue<pair<int, multiset<int>::iterator>> q;
multiset<int> s;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    cin >> n >> w;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = s.insert(x);
        q.push(make_pair(x, it));
        // cout << "i -> " << i << endl;
        // cout << "size -> " << s.size() << w+1 << endl;
        if (s.size() == w+1) {
            auto median = next(s.begin(), w/2);
            cout << *median << " ";
            auto fr = q.front();
            s.erase(fr.second);
            q.pop();
        }
    }
}