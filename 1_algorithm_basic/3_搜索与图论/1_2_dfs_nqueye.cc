// https://www.acwing.com/problem/content/845/
// n皇后
#include<bits/stdc++.h>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N*2], udg[N*2];


void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) puts(g[i]);
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
      // 斜对角线 y = x + b, b固定的都放在 b = y - x的元素，但是有可能小于0，所以加上n
      // 反对角线 y = -x + b, b = x + y
        if (!col[i] && !dg[u+i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    
    return 0;
}