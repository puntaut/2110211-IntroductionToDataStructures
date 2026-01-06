#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;
    int cap = 1;
    while (cap < size) cap *= 2;
    int notused = cap - size;
    cout << notused;
}