#include <iostream>
#include <map>

using namespace std;

bool hasfather(map<long, long> &dict, long son) {
    return dict.find(son) != dict.end();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int n,m;
    map <long, long> son2father_dict;
    cin >> n >> m;
    while (n--) {
        long father, son;
        cin >> father >> son;
        son2father_dict[son] = father;
    }
    while (m--) {
        long sibling1, sibling2;
        long father1, father2;
        long grandfather1, grandfather2;
        cin >> sibling1 >> sibling2;
        if (sibling1 == sibling2){
            cout << "NO" << endl;
        }
        else if (hasfather(son2father_dict, sibling1) && hasfather(son2father_dict, sibling2)) {
            father1 = son2father_dict[sibling1];
            father2 = son2father_dict[sibling2];
            if (hasfather(son2father_dict, father1) && hasfather(son2father_dict, father2)) {
                grandfather1 = son2father_dict[father1];
                grandfather2 = son2father_dict[father2];
                if (grandfather1 == grandfather2) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}