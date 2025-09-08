#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> aj_cards;
    for (int i = 0; i < n; i++) {
        int power;
        cin >> power;
        aj_cards[power] += 1;
    }

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
                it = aj_cards.upper_bound(x);
                if (it == aj_cards.end()) {
                    cout << i+1 << endl;
                    lose = true;
                    break;
                } else {
                    (*it).second -= 1;
                    if ((*it).second == 0) {
                        aj_cards.erase((*it).first);
                    }
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