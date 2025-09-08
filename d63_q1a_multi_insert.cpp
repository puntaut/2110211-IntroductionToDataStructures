#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
    //write your code here
    vector<int> u;

    int v_size = v.size();
    int u_size = v_size + count;
    u.resize(u_size);
    for (int i = 0; i < position; i++) {
        u.at(i) = v.at(i);
    }
    for (int i = 0; i < count; i++) {
        u.at(position + i) = value;
    }
    for (int i = 0; i < v_size - position; i++) {
        u.at(position + count + i) = v.at(position + i);
    }
    v = u;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,value,position,count;
    cin >> n >> value >> position >> count;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
        multiple_add(v,value,position,count);
        cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
    for (auto &x : v) cout << x << " ";
    cout << endl;
}