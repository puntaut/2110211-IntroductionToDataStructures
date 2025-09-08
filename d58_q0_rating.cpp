#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(2);
    int n;
    cin >> n;

    map<string, pair<int, int>> teacher2score;
    map<string, pair<int, int>> subject2score;
    for (int i = 0; i < n; i++) {
        string subject, teacher;
        int score;
        cin >> subject >> teacher >> score;
        if (teacher2score.find(teacher) == teacher2score.end()) {
            teacher2score[teacher] = {score, 1};
        } else {
            teacher2score[teacher].first += score;
            teacher2score[teacher].second += 1;
        }
        if (subject2score.find(subject) == subject2score.end()) {
            subject2score[subject] = {score, 1};
        } else {
            subject2score[subject].first += score;
            subject2score[subject].second += 1;
        }
    }
    string name;
    int sum;
    int count;
    for (auto it = subject2score.begin(); it != subject2score.end(); ++it) {
        name = (*it).first;
        sum = (*it).second.first;
        count = (*it).second.second;
        cout << name << " " << (sum+0.0)/count << endl;
    }
    for (auto it = teacher2score.begin(); it != teacher2score.end(); ++it) {
        name = (*it).first;
        sum = (*it).second.first;
        count = (*it).second.second;
        cout << name << " " << (sum+0.0)/count << endl;
    }
}