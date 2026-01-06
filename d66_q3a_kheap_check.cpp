#include <iostream>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int mSize,k;
        cin >> mSize >> k;
        vector<int> mData(mSize);

        bool is_end = false;
        bool is_heap = true;
        for (int i = 0; i < mSize; i++) cin >> mData[i];
        for (int i = 0; i < mSize; i++) {
            for (int j = 1; j <= k; j++) {
                int child_i = k * i + j;
                if (child_i >= mSize) {
                    is_end = true;
                    break;
                }
                if (mData[i] < mData[child_i]) {
                    is_heap = false;
                    break;
                }

            }
            if (is_end || !is_heap) {
                break;
            }
        }
        if (is_heap) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }

    }
}
