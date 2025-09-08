#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> sum;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum.at(i) -= x;
    }
    sort(sum.begin(), sum.end());
    for (int i = 0; i < n-1; i++) { 
        int target = 0 - sum.at(i);

        vector<int>::iterator target_index = upper_bound(sum.begin(), sum.end(), target);
        if (target_index > sum.begin() + i) {
            count += (sum.end()) - (target_index);
        } else {
            count += (sum.end()) - (sum.begin() + i + 1);
        }

    }
    cout << count << endl;
}