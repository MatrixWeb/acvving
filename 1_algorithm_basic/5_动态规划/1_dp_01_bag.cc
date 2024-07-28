// 0-1背包问题 https://www.acwing.com/activity/content/problem/content/997/
// f[i][j]: 前面i个物品，总体积不超过j的最大价值
// 状态转移方程：f[i][j] = max(f[i-1][j], f[i-1][j - v[i]] + w[i]) 考虑第i个选还是不选。
// 优化思路： （1）f全局变量，默认为0，不用初始化边界 （2）当前第i个物品只跟前面i-1状态有关，所以可以优化为一维数组。（3）j要反着计算才行
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
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] << endl;
    
    return 0;
}