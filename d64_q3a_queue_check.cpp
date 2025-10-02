#include <iostream>

using namespace std;

void print_correction (int mFront, int mSize, int mCap, int last) {
    if ( (mFront + mSize) % mCap != last || mFront >= mCap || mSize > mCap || last > mCap) {
        cout << "WRONG" << endl;
    } else {
        cout << "OK" << endl;
    }
}

void print_mFront (int mFront, int mSize, int mCap, int last) {
    if ((mFront + mSize) % mCap != last) {
        cout << "WRONG " << (last - mSize + mCap) % mCap << endl;
    } else if (mFront >= mCap) {
        cout << "WRONG " << (last - mSize + mCap) % mCap << endl;
    } else {
        cout << "OK" << endl;
    }
}

void print_mSize (int mFront, int mSize, int mCap, int last) {
    if ((mFront + mSize) % mCap != last) {
        cout << "WRONG " << (last - mFront + mCap) % mCap << endl;
    } else if (mSize > mCap) {
        cout << "WRONG " << (last - mFront + mCap) % mCap << endl;
    } else {
        cout << "OK" << endl;
    }
}

void print_mCap (int mFront, int mSize, int mCap, int last) {
    if (mFront == last && mSize != 0 && mSize != mCap) {
        cout << "WRONG " << mSize << endl;
    }
    else if ((mFront + mSize) % mCap != last || mCap == 0) {
        int mCapSol;
        if (mFront >= last) {
            mCapSol = (mFront-last) + mSize;
        } else {
            mCapSol = last+1;
        }
        cout << "WRONG " << mCapSol << endl;
    } else if (mCap < mSize) {
        cout << "WRONG " << mSize << endl; 
    } else {
        cout << "OK" << endl;
    }
} 

void print_last (int mFront, int mSize, int mCap, int last) {
    if ((mFront + mSize) % mCap != last) {
        cout << "WRONG " << (mFront + mSize) % mCap << endl;
    } else if (mSize >= mCap) {
        cout << "WRONG " << (mFront + mSize) % mCap << endl;
    } else {
        cout << "OK" << endl;
    }
}

int main() {
    int n;
    cin >> n;

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