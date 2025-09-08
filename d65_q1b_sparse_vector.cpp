#include <iostream>
#include <vector>
#include <map>
using namespace std;

void insert_into_sv(map<int,int> &v, int pos, int value) {
    //your code here
    auto it = v.lower_bound(pos);
    vector<pair<int, int>> u(it, v.end());
    it = v.erase(it, v.end());
    it = v.insert(it, {pos, value});
    for (auto p : u) {
        it = v.insert(it, {p.first+1, p.second});
    }

}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    map<int,int> v;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int a,b;
        cin >> a >> b;
        insert_into_sv(v,a,b);
    }
    cout << v.size() << "\n";
    for (auto &x : v) {
        cout << x.first << ": " << x.second << "\n";
    }
}