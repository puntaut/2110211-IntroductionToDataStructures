#include <iostream>

using namespace std;

bool is_possible(int mFront, int mSize, int mCap, int last) {
    return ((mFront + mSize) % mCap == last && mSize <= mCap && mFront < mCap && last < mCap);
}

int main() {
    int n;
    cin >> n;

    int mFront, mSize, mCap, last, correction;
    for (int i = 0; i < n; i++) {
        cin >> mFront >> mSize >> mCap >> last >> correction;
        if (correction == 0) {
            if (is_possible(mFront, mSize, mCap, last)) {
                cout << "OK\n";
            } else {
                cout << "WRONG\n";
            }
        } else if (correction == 1) {
            if (is_possible(mFront, mSize, mCap, last)) {
                cout << "OK\n";
            } else {
                cout << "WRONG " + to_string((last - mSize + mCap) % mCap) + "\n";
            }
        } else if (correction == 2) {
            if (is_possible(mFront, mSize, mCap, last)) {
                cout << "OK\n";
            } else {
                if (mFront == last) {
                    cout << "WRONG 0\n";
                } else if (mFront < last) {
                    cout << "WRONG " + to_string(last - mFront) + "\n";
                } else {
                    cout << "WRONG " + to_string(last + mCap - mFront) + "\n"; 
                }
            }
        } else if (correction == 3) {
            if (is_possible(mFront, mSize, mCap, last)) {
                cout << "OK\n";
            } else {
                if (mFront == last) {
                    if (mSize == 0) {
                        cout << "WRONG " + to_string(mFront + 1) + "\n";
                    } else {
                        cout << "WRONG " + to_string(mSize) + "\n";
                    }
                } else if (mFront < last) {
                    cout << "WRONG " + to_string(mFront + mSize + 1) + "\n";
                } else {
                    cout << "WRONG " + to_string(mFront - last + mSize) + "\n";
                }
            }
        } else {
            if (is_possible(mFront, mSize, mCap, last)) {
                cout << "OK\n";
            } else {
                cout << "WRONG " + to_string((mFront + mSize) % mCap) + "\n";
            }

        }



    }
}
