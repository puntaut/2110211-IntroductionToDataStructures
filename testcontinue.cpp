#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            cout << i << endl;
            continue;
        } else {
            cout << i << endl;
        }
    }
}