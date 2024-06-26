// https://www.acwing.com/problem/content/880/
// 扩展欧几里得解线性同余方程
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y  = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int a, b, m;
        cin >> a >> b >> m;
        
        int x, y;
        int d = exgcd(a, m, x, y);
        if (b % d) puts("impossible");
        else cout << (LL) b / d * x % m << endl;
    }
    return 0;
}