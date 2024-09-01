// https://www.acwing.com/problem/content/93/
// 最短哈密顿路径。i表示路径二进制集合
// f[i][j] = min(f[x][k] + w[k][j]), k = 0, ... , n - 1, x = i - (1<<j)。按倒数第二个经过的点进行划分
#include <bits/stdc++.h>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int w[N][N];
int f[M][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
    
    cout << f[(1 << n) - 1][n - 1];
    return 0;
}