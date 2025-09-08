#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void member_multiply(vector<int> &v,
    vector<pair<vector<int>::iterator,int>> &multiply) {
    //write your code here
    sort(multiply.begin(), multiply.end());
    vector<int> u;
    if (multiply.size() > 0) {
        pair<vector<int>::iterator,int> pair;
        vector<int>::iterator it;
        int n;
        for (int i = 0; i < multiply.size(); i++) {
            pair = multiply.at(i);
            it = pair.first;
            n = pair.second;
            if (i == 0) {
                u.insert(u.end(), v.begin(), it);
                u.insert(u.end(), n, *it);
            } else {
                auto prev_it = multiply.at(i-1).first;
                u.insert(u.end(), prev_it, it);
                u.insert(u.end(), n, *it);
            }
        }
        u.insert(u.end(), it, v.end());

        v = u;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator,int>> multiply(m);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    for (int i = 0;i < m;i++) {
        int a,b;
        cin >> a >> b;
        multiply[i].first = v.begin()+a;
        multiply[i].second = b;
    }
    member_multiply(v,multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}