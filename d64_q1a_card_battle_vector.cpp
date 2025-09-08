#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> aj_cards(n);
    for (int i = 0; i < n; i++) {
        cin >> aj_cards[i];
    }

    sort(aj_cards.begin(), aj_cards.end());

    auto it = aj_cards.begin();
    bool lose = false;

    for (int i = 0; i < m; i++) {
        if (lose) break;
        int count;
        cin >> count;
        for (int j = 0; j < count; j++) {
            int x;
            cin >> x;
            if (aj_cards.size() != 0) {
                it = upper_bound(aj_cards.begin(), aj_cards.end(), x);
                if (it == aj_cards.end()) {
                    cout << i+1 << endl;
                    lose = true;
                    break;
                } else {
                    aj_cards.erase(it);
                    continue;
                }
            } else {
                cout << i+1 << endl;
                lose = true;
                break;
            }
        }
    }
    if (!lose) {
        cout << m+1 << endl;
    }
}