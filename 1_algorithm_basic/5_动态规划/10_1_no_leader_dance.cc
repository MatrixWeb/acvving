// https://www.acwing.com/problem/content/287/
// 树形DP
// f[u][0] : 所有从子树选，并且不选父节点u的方案最大值
// f[u][1] : 所有从子树选，并且选父节点u的方案最大值
#include <bits/stdc++.h>

using namespace std;

const int N = 6010;

int n;
int h[N], e[N], ne[N], idx;
int happy[N];
int f[N][2];
bool has_fa[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    f[u][1] = happy[u];
    
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        dfs(j);
        // dp转移方程
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][0], f[j][1]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> happy[i];
    
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);
        has_fa[a] = true;
    }
    int root = 1;
    while(has_fa[root]) root++;
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    
    return 0;
}