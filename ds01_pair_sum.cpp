// #pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <map>

using namespace std;

bool has_that_pair( int arr[], map<int, int> &dict ,int arr_size, int sum) {
    int x;
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > sum) {
            continue;
        } else {
            x = sum - arr[i];
            if (x < 0) {
                continue;
            } else if (arr[i] == x) {
                if (dict.find(x) != dict.end()) {
                    if (dict[x] > 1) {
                        return true;
                    }
                }
            } else {
                if (dict.find(x) != dict.end()) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    int arr[n];
    map<int, int> dict;
    int ans;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr[i] = x;
        if (dict.find(x) != dict.end()) {
            dict[x] += 1;
        } else {
            dict[x] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> ans;
        if (has_that_pair(arr, dict, n, ans)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        };
    }

}