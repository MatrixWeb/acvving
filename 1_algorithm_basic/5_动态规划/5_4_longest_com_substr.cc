// https://www.acwing.com/problem/content/899/
// 最长公共子序列
// f[i][j] : a[0..i]和b[0..j]最长公共子序列长度
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N];
int f[N][N];

int main() {
    scanf("%d%d", &n, &m);
   scanf("%s%s", a + 1, b + 1);
   for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        f[i][j] = max(f[i-1][j], f[i][j-1]);
        if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
    }
    cout << f[n][m] << endl;
    return 0;
}