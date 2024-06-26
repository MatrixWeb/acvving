// https://www.acwing.com/problem/content/206/
// 中国剩余定理解一次同余方程
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    cin >> n;
    
    LL x = 0;
    LL a1, m1;
    cin >> a1 >> m1;
    // 两个同余方程不断合并到一个
    // x = k1a1 + m1 ... (2)
    // x = k2a2 + m2
    for (int i = 0; i < n - 1; i++) {
        LL a2, m2;
        cin >> a2 >> m2;
        
        LL k1, k2;
        // 算出k1*a1 + k2 * a2 = m2 - m1 ... (1), k1, k2是未知数 的一个解。
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d) {
            x = -1;
            break;
        }
        k1 *= (m2 - m1) / d;
        // 利用不定方程(1)求出k1最小的一个解 :k1 = k` + a2/d * t, t = 0, 1, 2, ...
        k1 = (k1 % (a2 / d) + (a2 / d)) % (a2 / d); // 此时k1算出的是k`
        // 把这个解带入（2）式，求的x，然后更新m1, a1
        // x = (k` + a2/d * t)a1 + m1 = t * (a1*a2 / d) + (k`a1 + m1) 可得x 同余 (k`a1 + m1) (mod (a1*a2 / d)) 跟同余方程具备相同结构
        m1 = k1 * a1 + m1;
        a1 = abs(a1 / d * a2);
        // 完成合并
    }
    if (x != -1) x = ((m1 % a1) + a1) % a1;
    cout << x ;
    return 0;
    
}