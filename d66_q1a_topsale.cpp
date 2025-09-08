#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    map<int, int> id2sale;
    map<int, set<int>> sale2ids;
    while (n--) {
        int id;
        cin >> id;
        id2sale[id] = 0;
    }
    while (m--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int id, new_amount;
            cin >> id >> new_amount;
            if (id2sale.find(id) == id2sale.end()) continue;

            int old_amount = id2sale[id];
            new_amount +=  old_amount;
            // id2sale[id] =  new_amount;
            // if (sale2ids.find(old_amount) == sale2ids.end()) {
            //     sale2ids[new_amount] = {id};
            // } else {
            //     sale2ids[old_amount].erase(id);

            //     // erase that key-pair value if set is remain to zero
            //     if (sale2ids[old_amount].size() == 0) {
            //         sale2ids.erase(old_amount);
            //     }
            //     sale2ids[new_amount].insert(id);
            // }
            if (old_amount > 0) {
                sale2ids[old_amount].erase(id);
                if (sale2ids[old_amount].size() == 0) {sale2ids.erase(old_amount);}
            }
            id2sale[id] = new_amount;
            sale2ids[new_amount].insert(id);

        } else if (cmd == 2) {
            int f;
            cin >> f;
            auto it = sale2ids.lower_bound(f);
            if (sale2ids.size() == 0 || it == sale2ids.begin()) {
                cout << "NONE" << endl;
            } else {
                if (prev(it)->first == 0) {
                    cout << "NONE" << endl;
                } else {
                    cout << *prev((prev(it)->second).end()) << endl;
                }
            }
            
        }
    }
}