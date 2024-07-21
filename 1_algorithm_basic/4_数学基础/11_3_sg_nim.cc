// https://www.acwing.com/problem/content/895/
// sg函数
// sg(终局) = 0
// sg(当前) = mex(sg(后续)) ， mex运算是在一堆数字集合找当前不存在的最小非负整数
// 算出每一堆的sg后，当成nim游戏
// 性质1: sg(当前) = a， 根据mex定义，下一次一定能扭转到比a小的数
// 先手必胜：sg(开始点)异或和不为0。通过性质1，以及之前nim的特性，把所有异或和变为0即可。
#include <bits/stdc++.h>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int s[N], f[M];

int sg(int x) {
    if (f[x] != -1) return f[x];
    
    unordered_set<int> S;
    for (int i = 0; i < m; i++) {
        int sum = s[i];
        if (x >= sum) S.insert(sg(x - sum));
    }
    for (int i = 0; ; i++) {
        if (!S.count(i)) {
            return f[x] = i;
        }
    }
}

int main() {
    cin >> m;
    for (int i = 0; i < m; i++) cin >> s[i];
    cin >> n;
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if (res) puts("Yes");
    else puts("No");
    
    return 0;
}