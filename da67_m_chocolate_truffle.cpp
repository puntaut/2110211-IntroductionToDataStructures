#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

ll distance(ll ans, ll fav, ll n) {
    if (fav >= ans) {
        return fav - ans;
    } else {
        return (n + fav - ans);
    }
}

ll fav_distance(vector<ll> &v, ll pq_i, ll n) {
    auto it = lower_bound(v.begin(), v.end(), pq_i);
    if (it == v.begin() || it == v.end()) {
        ll d1 = distance(pq_i, *(v.begin()), n);
        ll d2 = distance(pq_i, *prev(v.end()), n);
        return d1 <= d2 ? d1 : d2; 
    } else {
        ll d1 = distance(pq_i, *it, n);
        ll d2 = distance(pq_i, *prev(it), n);
        return d1 <= d2 ? d1 : d2;
    }
}

int main () {
    ll ROW, COL, k;
    cin >> ROW >> COL >> k;

    ll n = ROW * COL;

    bool has_max = false;
    ll max;

    vector<ll> v;

    for (ll i = 0; i < k; i++) {
        ll p, q;
        cin >> p >> q;

        ll fav_i = (COL*(p-1)) + q;
        v.push_back(fav_i);
    }
    sort(v.begin(), v.end());
    ll n_ans;
    cin >> n_ans;
    for (ll i = 0; i < n_ans; i++) {
        ll p_ans, q_ans;
        cin >> p_ans >> q_ans;

        ll pq_i = (COL*(p_ans-1)) + q_ans;
        
        cout << fav_distance(v, pq_i, n) << endl;
    }
}