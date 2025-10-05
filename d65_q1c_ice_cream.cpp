#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int ceiling_divide(int a, int b) {
    return  (a / b) + (a % b != 0);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;

    map<int, int> day2s;
    day2s[0] = start;

    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        day2s[a] = s;
    }

    for (int i = 0; i < m; i++) {
        // int d = 0;
        int P, x;
        cin >> P >> x;

        int sum = 0;

        auto it = day2s.begin();
        auto robbed_it = day2s.lower_bound(x);

        robbed_it = (robbed_it->first == x) ? robbed_it : prev(robbed_it);

        int d1,d2,s1,s2,dx,d;
        while (sum < P) {
            d1 = it->first;
            s1 = it->second;

            dx = ceiling_divide(P-sum, s1);

            if (it != robbed_it) { // non-robbed case
                if (it != prev(day2s.end())) { // non-last element
                    auto it2 = next(it);
                    d2 = it2->first;
                    // s2 = it2->second;

                    if (d1 + (dx - 1) <= d2 - 1) { // complete
                        sum += dx * s1;
                        d = d1 + (dx - 1);
                        break;
                    } else { // incomplete
                        sum += (d2 - d1) * s1;
                        it++;
                    }
                } else { // last element
                    sum += dx * s1;
                    d = d1 + (dx - 1);
                    break;
                }
            } else { // robbed case
                if (it != prev(day2s.end())) {
                    auto it2 = next(it);
                    d2 = it2->first;

                    if (d1 + (dx - 1) <= x) { // complete before being robbed
                        d = d1 + (dx - 1);
                        sum += dx * s1;
                        break;
                    } else {
                        sum = 0;
                        dx = ceiling_divide(P, s1);
                        if ((x + 1) + (dx - 1) <= d2 - 1) { // complete after begin robbed
                            d = (x + 1) + (dx - 1);
                            sum += dx * s1;
                            break;
                        } else { // incomplete
                            sum += (d2 - (x + 1)) * s1;
                            it++;
                        }
                    }


                } else {
                    if (d1 + (dx - 1) <= x) { // complete before being robbed
                        sum += dx * s1;
                        d = d1 + (dx - 1);
                        break;
                    } else { // complete after being robbed
                        sum = 0;
                        dx = ceiling_divide(P, s1);
                        d = (x + 1) + (dx - 1);
                        sum += dx * s1;
                        break;
                    }
                }
            }
        }
        cout << d << " ";
    }
    cout << endl;



}