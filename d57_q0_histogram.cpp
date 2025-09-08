#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());

    auto it = v.begin();
    string check = *it;
    int count = 1;
    if (v.size() >= 2) {
        ++it;
        while (it != v.end()) {
            if (*it == check) {
                count += 1;
            } else {
                if (count > 1) {
                    cout << check << " " << count << endl;
                } 
                check = *it;
                count = 1;
            }
            ++it;
        }
        if (count > 1) {
            cout << check << " " << count << endl;
        }
    }
}