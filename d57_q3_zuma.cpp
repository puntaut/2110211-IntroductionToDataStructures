#include <iostream>
#include <list>

using namespace std;

bool isNotEdge(list<int> &l, list<int>::iterator it) {
    return (it != l.end() && it != l.begin());
}

bool isSameColor(list<int> &l, list<int>::iterator it) {
    if (isNotEdge(l, it)) return *prev(it) == *it;
    return false;
}

pair<list<int>::iterator, int> check_left(list<int> &l, list<int>::iterator it) {
    int count = 0;
    int color = *it;
    while (it != l.begin()) {
        it--;
        if (*it == color) {
            count++;
        } else {
            ++it;
            break;
        }
    }
    return make_pair(it, count);
}

pair<list<int>::iterator, int> check_right(list<int> &l, list<int>::iterator it) {
    int count = 0;
    int color;
    while (it != l.end()) {
        if (count == 0) {
            color = *it;
            count++;
            ++it;
        } else if (*it == color ) {
            count++;
            ++it;
        } else {
            break;
        }
    }
    return make_pair(it, count);
}

pair<bool, list<int>::iterator> crash(list<int> &l, list<int>::iterator it) {
    if (isNotEdge(l, it)) {
        auto left = check_left(l, it);
        auto right = check_right(l, it);
        if (left.second > 0 && left.second + right.second >= 3) {
            l.erase(left.first, right.first);
            return make_pair(true, right.first);
        } else {
            return make_pair(false, it);
        }
    } else {
        return make_pair(false, it);
    }
}

pair<bool, list<int>::iterator> shoot(list<int> &l, list<int>::iterator it, int color) {
    it = l.insert(it, color);
    auto left = check_left(l, it);
    auto right = check_right(l, it);
    if (left.second + right.second >= 3) {
        l.erase(left.first, right.first);
        return make_pair(true, right.first);
    } else {
        return make_pair(false, it);
    }
}

int main() {
    int n, pos, color;
    cin >> n >> pos >> color;

    list<int> l;
    int color_i;
    list<int>::iterator it = l.end();
    for (int i = 0; i < n; i++) {
        cin >> color_i;
        auto x = l.insert(l.end(), color_i);
        if (i == pos) it = x;
    }
    if (l.size() == 0) {
    } else {
        bool dodo = false;
        auto jkl = shoot(l, it, color);
        dodo = jkl.first;
        it = jkl.second;
        while (dodo) {
            jkl = crash(l, it);
            dodo = jkl.first;
            it = jkl.second;
        }
    }
    for (auto &x : l) {
        cout << x << " ";
    }

}
