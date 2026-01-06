#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int mSize, idx;
    cin >> mSize >> idx;

    queue<int> q;
    vector<int> v;

    q.push(idx);
    v.push_back(idx);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        if (2*idx+1 < mSize) {
            q.push(2*idx+1);
            v.push_back(2*idx+1);
        }
        if (2*idx+2 < mSize) {
            q.push(2*idx+2);
            v.push_back(2*idx+2);
        }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}
