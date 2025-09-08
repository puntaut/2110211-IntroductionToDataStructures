#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,int a,int b) {
    //write your code only in this function

    int n_rev = b - a + 1;
    int u[n_rev];
    for (int i = 0; i < n_rev; i++) {
        u[n_rev - i - 1] = v.at(a+i);
    }
    for (int i = 0; i < n_rev; i++) {
        v.erase(v.begin() + a + i);
        v.insert(v.begin()+ a + i, u[i]);
    }
    
}
int main() {
    //read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    //call function
    reverse(v,a,b);
    //display content of the vector
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}