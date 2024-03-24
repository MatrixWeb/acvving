// 字符串hash
#include <bits/stdc++.h>

using namespace std;

// 定义这个相当于值 % 2^64
typedef unsigned long long ULL;

// P是经验值，取这个hash冲突少
const int N = 1e5 + 10, P = 131;

int n, m;
// 下标从1开始
char str[N];
// h[0] = 0, h[1] = str[1..1]的hash值， ... , h[x] = str[1..x]的hash值
// p[0] = P^0, ..., p[x] = P^x, 
ULL h[N], p[N];

// 子串hash值公式
ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m;
    cin >> str + 1;
    p[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    
    while( m --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }
    return 0;
}