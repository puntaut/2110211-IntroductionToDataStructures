#include <iostream>

using namespace std;

int main() {
    size_t n,k;
    cin >> n >> k;

    size_t n1, n2;
    cin >> n1 >> n2;

    size_t lowest_node = 0;
    if (n1 == n2) {
        lowest_node = n1;
    }
    while (n1 != n2) {
        if (n1 < n2) {
            n2 = (n2 - 1) / k;
        } else {
            n1 = (n1 - 1) / k;
        }

        if (n1 == n2) {
            lowest_node = n1;
            break;
        }
    }
    cout << lowest_node << endl;
}

