#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int mSize,idx;
    cin >> mSize >> idx;
    int s = mSize;
    int t = idx + 1;
    int height = 0;
    int idx_height = 0;
    while (s > 1) {
        s /= 2;
        height++;
    }
    while (t > 1) {
        t /= 2;
        idx_height++;
    }

    int left_most = 0;
    int right_most = 0;
    int idx_left,idx_right;
    int count = 0;
    vector<int> v;
    for (int i = 0; i < height+1; i++) {
        // cout << "i: " << i <<endl; 
        // updating left_most and right_most
        if (i != 0) {
            left_most = 2*left_most + 1;
            right_most = min(2*right_most+2, mSize-1);
        }

        // checking intersection
        bool is_intersect = false;
        if (i == idx_height) {
            idx_left = idx;
            idx_right = idx;
            is_intersect = true;
        } else if (i > idx_height) {
            idx_left = 2*idx_left+1;
            idx_right = min(2*idx_right+2, mSize-1);
            if (idx_left <= mSize - 1) is_intersect = true;
        }
        if (!is_intersect) {
            count += right_most-left_most+1;
            for (int i = left_most; i <= right_most; i++) v.push_back(i);
            // cout << "case 1: left_most = " << left_most << ", right_most = " << right_most << endl; 
        } else {
            count += (right_most-left_most+1) - (idx_right-idx_left+1);
            for (int i = left_most; i < idx_left; i++) v.push_back(i);
            for (int i = idx_right+1; i <= right_most; i++) v.push_back(i);
            // cout << "case 2: left_most = " << left_most << ", right_most = " << right_most << endl; 
            // cout << "case 2: idx_left = " << idx_left << ", idx_right = " << idx_right << endl; 
        }
    }
    // cout << count << endl;
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
}
