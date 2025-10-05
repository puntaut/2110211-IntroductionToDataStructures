#include <iostream>

using namespace std;

bool isPossible (int mFront, int mSize, int mCap, int last) {
    if (mFront >= mCap || last >= mCap || mSize > mCap) return false;

    if (mFront == last) {
        return mSize == mCap || mSize == 0;
    } else if (mFront < last) {
        return mSize == last - mFront;
    } else {
        return mSize == last + mCap - mFront;
    }
}

void print_correction (int mFront, int mSize, int mCap, int last) {
    if (isPossible(mFront, mSize, mCap, last)) {
        cout << "OK\n";
    } else {
        cout << "WRONG\n";
    }
}

void print_mFront (int mFront, int mSize, int mCap, int last) {
    if (isPossible(mFront, mSize, mCap, last)) {
        cout << "OK\n";
    } else {
        if (0 + mSize <= last) {
            cout << "WRONG " + to_string(last - mSize) + "\n";
        } else {
            cout << "WRONG " + to_string(last - mSize + mCap) + "\n";
        }
    }
}

void print_mSize (int mFront, int mSize, int mCap, int last) {
    if (isPossible(mFront, mSize, mCap, last)) {
        cout << "OK\n";
    } else {
        if (mFront == last) {
            cout << "WRONG " + to_string(0) + "\n";
        } else if (mFront < last) {
            cout << "WRONG " + to_string(last - mFront) + "\n";
        } else {
            cout << "WRONG " + to_string(last + mCap - mFront) + "\n";
        }
    }
}

void print_mCap (int mFront, int mSize, int mCap, int last) {
    if (isPossible(mFront, mSize, mCap, last)) {
        cout << "OK\n";
    } else {
        if (mFront == last) {
            if (mSize == 0) {
                cout << "WRONG " + to_string(last + 1) + "\n";
            } else {
                cout << "WRONG " + to_string(mSize) + "\n";
            }

        } else if (mFront < last) {
            cout << "WRONG " + to_string(last + 1) + "\n";
        } else {
            // mSize = last + mCap - mFront;
            cout << "WRONG " + to_string(mSize - last + mFront) + "\n";
        }
    }
} 

void print_last (int mFront, int mSize, int mCap, int last) {
    if (isPossible(mFront, mSize, mCap, last)) {
        cout << "OK\n";
    } else {
        if (mFront + mSize < mCap) {
            cout << "WRONG " + to_string(mFront + mSize) + "\n";
        } else {
            cout << "WRONG " + to_string(mFront + mSize - mCap) + "\n";
        }
    }
}

int main() {
    int n;
    cin >> n;

    // string s;
    while (n--) {
        int mFront, mSize, mCap, last, correction;

        cin >> mFront >> mSize >> mCap >> last >> correction;
        if (correction == 0) {
            print_correction(mFront, mSize, mCap, last);
        } else if (correction == 1) {
            print_mFront(mFront, mSize, mCap, last);
        } else if (correction == 2) {
            print_mSize(mFront, mSize, mCap, last);
        } else if (correction == 3) {
            print_mCap(mFront, mSize, mCap, last);
        } else {
            print_last(mFront, mSize, mCap, last);
        }
    }
}