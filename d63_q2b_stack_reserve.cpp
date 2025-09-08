#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    stack<int> st;
    cin >> n;
    v.resize(n);
    int first;
    int second;
    for(int i = 0; i < n; i++) {
        cin >> first >> second;
        v[i] = make_pair(first, second);
    }

    int sol;
    for (auto &p : v) {
        if (p.first == 1) {
            st.push(p.second);
        } else if (p.first == 0) {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            if (p.second == 0) {
                sol = operand1 + operand2;
            } else if (p.second == 1) {
                sol = operand1 - operand2;
            } else if (p.second == 2) {
                sol = operand1 * operand2;
            } else if (p.second == 3) {
                sol = operand1 / operand2;
            }
            st.push(sol);
        }
    }
    cout << st.top() << endl;
}