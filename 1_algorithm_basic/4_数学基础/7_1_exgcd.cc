// https://www.acwing.com/problem/content/879/
// 扩展欧几里得算法
#include <bits/stdc++.h>

using namespace std;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    cin >> n;
    while( n--) {
        int a , b;
        cin >> a >> b;
        int x , y;
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
    return 0;
}