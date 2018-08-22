// https://open.kattis.com/problems/aboveaverage

#include <iostream>
#include <iomanip>

using namespace std;

const int N_MAX = 1000;

int main(void) {
    int c, n, i;
    int p[N_MAX];
    double sum, avg;
    cin >> c;
    while (c--) {
        cin >> n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            sum += p[i];
        }
        avg = sum / n;
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] > avg) {
                sum += 1;
            }
        }
        sum = sum / n * 100;
        cout << fixed << setprecision(3) << sum << "%" << endl;
    }
    return 0;
}