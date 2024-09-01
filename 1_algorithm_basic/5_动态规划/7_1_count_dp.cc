// https://www.acwing.com/problem/content/902/
// 完全背包的解法
// f[i][j]表示只从1~i中选，且总和等于j的方案数
// f[i][j] = f[i-1][j] + f[i-1][j - i] + ... + f[i-1][j - s*i] 最好一个为i的选几个枚举
// f[i][j - i] = [i-1][j - i] + ... + f[i-1][j - s*i]
// 推出 f[i][j] = f[i-1][j] + f[i][j - i]
#include <bits/stdc++.h>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N];

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % mod;
    cout << f[n] << endl;
    return 0;
}