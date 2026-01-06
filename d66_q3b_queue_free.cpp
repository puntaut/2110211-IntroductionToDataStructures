#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long size = 0;
    long long cap = 1;
    
    int a;
    long long k;

    while (n--) {
        cin >> a >> k;
        if (a == 0) {
            size += k;
            while (size > cap) cap <<= 1;
        } else {
            size -= k;
        }

    }
    cout << cap - size << endl;
}
