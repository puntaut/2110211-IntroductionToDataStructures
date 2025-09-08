#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);
    cin >> n >> m;
    map <string, set<string>> airline2seats;
    while (n--) {
        string airline, seat;
        cin >> airline >> seat;
        airline2seats[airline].insert(seat);
    }

    while (m--) {
        int seatCount;
        string airlineQ, seatQ;

        cin >> seatCount;
        vector<pair<string, string>> seats;
        seats.resize(seatCount);

        // for (auto &p : airline2seats) {
        //     cout << "airline: " << p.first << endl;
        //     for (auto it = p.second.begin(); it != p.second.end(); ++it) {
        //         cout << "seat: " << *it << endl;
        //     }
        // }

        bool available = true;
        for (int i = 0; i < seatCount; i++) {
            cin >> airlineQ >> seatQ;
            seats[i] = {airlineQ, seatQ};
            
            if (!available) {
                continue;
            } else if (airline2seats.find(airlineQ) != airline2seats.end() && airline2seats[airlineQ].find(seatQ) != airline2seats[airlineQ].end()) {
                ;
            } else {
                available = false;
            }
        }
        if (!available) {
            cout << "NO" << endl;
            // seats.clear();
            continue;
        } else {
            cout << "YES" << endl;
        }

        // cout << "seats: " << endl;
        // for (auto &p : seats) {
        //     cout << p.first << " " << p.second << " ";
        // }

        for (int i = 0; i < seatCount; i++) {
            // cout << "xxx" << endl;
            // cout << "seat_i " << (seats[i]).first << (seats[i]).second << endl;
            airline2seats[seats[i].first].erase(seats[i].second);
            if (airline2seats[seats[i].first].size() == 0) {
                airline2seats.erase(seats[i].first);
                // cout << "yyy" << endl;
            }
        }



        // seats.clear();


        
    }
}