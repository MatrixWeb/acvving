// 矩阵前缀和
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m, q;
int s[N][N];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &s[i][j]);
    
    // 固定公式， 求一遍前缀和数组
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
    
    while (q --) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        // 利用前缀和数组，求出子矩阵的和
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }
    return 0;
}