#include <iostream>

using namespace std;

int more_val(int a, int b) {
    return (a > b) ? a : b;
}
int less_val(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    int m;
    int test_count;
    cin >> n >> m;
    cin >> test_count;
    int rows[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }
    // cout << "Matrix accepted" << endl;
    for (int i = 0; i < test_count; i++) {
        int x;
        int test_i[4];
        for (int j = 0; j < 4; j++) {
            cin >> test_i[j];
        }
        if ( test_i[0] > test_i[2] || test_i [1] > test_i[3] ) {
            cout << "INVALID" << endl;
        }
        else if ( test_i[2] < 1 || test_i[3] < 1 || test_i[0] > n || test_i[1] > m ) {
            cout << "OUTSIDE" << endl;
        }
        else {
            int a1 = more_val(0, test_i[0]-1);
            int a2 = less_val(n-1, test_i[2]-1);
            int b1 = more_val(0, test_i[1]-1);
            int b2 = less_val(m-1, test_i[3]-1);
            for (int i = a1; i <= a2; i++) {
                for (int j = b1; j <= b2; j++) {
                    if (i == a1 && j == b1) {
                        x = rows[i][j];
                    }
                    if (rows[i][j] > x) {
                        x = rows[i][j];
                    }
                }
            }

            cout << x << endl;
        }
    }
    return 0;
}
