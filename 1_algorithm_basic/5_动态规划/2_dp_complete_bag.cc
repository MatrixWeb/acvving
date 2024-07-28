// https://www.acwing.com/problem/content/3/
// 完全背包问题
// f[i][j]: 前面i个物品，总体积不超过j的最大价值
// 状态转移方程： f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
// 优化： f[i][j]=max(f[i-1][j],f[i][j-v]+w)
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] << endl;
    
    return 0;
}