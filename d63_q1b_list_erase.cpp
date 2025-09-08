#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void list_erase(vector<int> &v, vector<int> &pos) {
    //write your code here
    // sort(pos.begin(), pos.end(), greater<int>());

    vector<int> tmp;
    int pos_size = pos.size();
    int v_size = v.size();
    int n = v_size - pos_size;

    tmp.resize(n);
    sort(pos.begin(), pos.end());

    int tmp_i = 0;
    auto it = pos.begin();
    for (int v_i = 0; v_i < v.size(); v_i++) {
        if (it != pos.end() && v_i == *it) {
            it++;
        } else {
            tmp[tmp_i] = v[v_i];
            tmp_i++;
        }
    }
    v = tmp;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n), pos(m);
    for (int i = 0;i < n;i++) cin >> v[i];
    for (int i = 0;i < m;i++) cin >> pos[i];
    list_erase(v,pos);
    cout << "After call list_erase" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}