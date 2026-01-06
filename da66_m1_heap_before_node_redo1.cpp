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

    while(!q.empty()) {
        int i = q.front();
        q.pop();
        if (2*i+1 < mSize) {
            q.push(2*i+1);
            v.push_back(2*i+1);
        } 
        if (2*i+2 < mSize) {
            q.push(2*i+2);
            v.push_back(2*i+2);
        }
    }
    int f_size = mSize - v.size();
    auto it = v.begin();
    cout << f_size << endl;
    for (int i = 0; i < mSize; i++) {
        if (it != v.end() && *it == i) {
            ++it;
        } else {
            cout << i << " ";
        }
    }

}
