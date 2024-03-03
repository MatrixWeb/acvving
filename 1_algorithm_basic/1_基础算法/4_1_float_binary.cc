#include <bits/stdc++.h>

using namespace std;

int main() {
    double x;
    cin >> x;
    double l = -100, r = 100;
    // 题目要求结果保留 6位小数，这里要保持1e-8
    while(r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    printf("%0.6f\n", l);
    return 0;
}