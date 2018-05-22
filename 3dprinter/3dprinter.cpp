// https://open.kattis.com/problems/3dprinter

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n; // [1; 10_000]
    cin >> n;
    cout << ceil( log(n)/log(2) ) + 1 << endl;
    return 0;
}