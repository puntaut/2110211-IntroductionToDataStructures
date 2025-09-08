#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> wordfreq;
    int n;
    cin >> n;

    bool has_max = false;
    int max_value;
    string max_name;
    while (n--) {
        string name;
        cin >> name;
        wordfreq[name] += 1;
        if (!has_max) {
            max_value = 1;
            has_max = true;
        } else {
            if ((wordfreq[name] > max_value)) {
                max_name = name;
                max_value = wordfreq[name];
            } else if (wordfreq[name] == max_value && name >= max_name ) {
                max_name = name;
            }
        }
    }
    cout << max_name << " " << max_value << endl;
}