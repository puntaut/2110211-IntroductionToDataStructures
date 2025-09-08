#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> char2num;
    for (int i = 0; i < 26; i++) {
        char2num[alphabet[i]] = i;
    }

    int n, m, l;
    cin >> n >> m >> l;
    vector<int> encode(l);
    set<string> database;
    for (int i = 0; i < l; i++) {
        int k;
        cin >> k;
        k %= 26;
        encode[i] = k;
    }
    for (int i = 0; i < n; i++) {
        string password;
        cin >> password;
        database.insert(password);
    }
    for (int i = 0; i < m; i++) {
        string q;
        cin >> q;
        for (int j = 0; j < l; j++) {
            q[j] = alphabet[(26 + char2num[q[j]]+ encode[j]) % 26];
        }
        auto it = database.find(q);
        if (it != database.end()) {
            cout << "Match\n";
        } else {
            cout << "Unknown\n";
        }
    }
}