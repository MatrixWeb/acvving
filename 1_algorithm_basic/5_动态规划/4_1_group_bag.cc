// https://www.acwing.com/problem/content/9/
// 分组背包问题 f[i][j]=max(f[i][j],f[i-1][j-v[i][k]]+k*w[i][k]); 第i组选第k个
#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n ;i++) {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }
    // 一维数组优化的时候，体积要倒着算，这样就可以使用上一次计算的数组
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k < s[i]; k++)
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
    
    cout << f[m] << endl;
    
    return 0;
}