#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    size_t n;
    vector<stack<int>> ancestor_info;
    cin >> n;
    if (n == 1)
    for (size_t i = 0; i < n; i++) {
        size_t x;
        cin >> x;
        if (x == 0) cout << "0\n";
        while (x != 0) {
            ancestor_info[i].push(x);
            x = (x - 1) / 2;
        }
    }

}
