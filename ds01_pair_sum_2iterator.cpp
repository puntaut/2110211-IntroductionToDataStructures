#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr, arr+n);
    while (m--) {
        int sum;
        int i = 0;
        int j = n-1;
        cin >> sum;
        bool found = false;
        while (i < j) {
            if (arr[i] + arr[j] == sum) {
                found = true;
                break;
            } else if (arr[i] + arr[j] > sum) {
                j--;
            } else {
                i++;
            }
        }
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }
}