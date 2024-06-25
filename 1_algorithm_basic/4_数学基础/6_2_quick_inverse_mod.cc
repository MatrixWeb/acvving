// https://www.acwing.com/problem/content/878/
// 快速幂求逆元
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, p;
        cin >> a >> p;
        if (a % p == 0) puts("impossible");
        else cout << qmi(a, p - 2, p) << endl;
    }
    return 0;
}