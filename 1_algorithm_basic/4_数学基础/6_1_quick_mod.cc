// https://www.acwing.com/problem/content/877/
// 快速幂
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p) {
    LL res = 1 % p;
    while(b) {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    while(n --) {
        int a, b, p;
        cin >> a >> b >> p;
        cout << qmi(a, b, p) << endl;
    }
    return 0;
}