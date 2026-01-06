#include <iostream>
#include <queue>

using namespace std;

int main() {
    int mSize, n;
    cin >> mSize >> n;

    int a,b;
    while (n--) {
        cin >> a >> b;
        bool is_swapped = false;

        if (a == b) {
            cout << "a and b are the same node\n";
            continue;
        } else if (a > b) {
            swap(a,b);
            is_swapped = true;
        }
        // now always a < b

        queue<int> q;
        q.push(a);
        bool found = false;
        while (!q.empty()) {
            int f = q.front();
            if (f == b) {
                found = true;
                break;
            } else if (f > b) {
                break;
            }
            q.pop();
            if (2*f+1 < mSize) {
                q.push(2*f+1);
            }
            if (2*f+2 < mSize) {
                q.push(2*f+2);
            }
        }
        if (found) {
            if (is_swapped) {
                cout << "b is an ancestor of a\n";
            } else {
                cout << "a is an ancestor of b\n";
            }
        } else {
            cout << "a and b are not related\n";
        }

    }
}
