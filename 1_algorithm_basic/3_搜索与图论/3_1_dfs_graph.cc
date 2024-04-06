// https://www.acwing.com/problem/content/848/
// 树的重心，图的深度优先遍历
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int ans = N;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 返回以u为根节点的树节点个数
int dfs(int u) {
    st[u] = true;
    int size = 0, sum = 0;
    
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (st[j]) continue;
        
        int s = dfs(j);
        size  = max(size, s);
        // 累加所有子节点数
        sum += s;
    }
    // size表示目前以u为重心的话，其他联通块的节点数最大值。上面的部分是n - sum - 1.
    size = max(size, n - sum - 1);
    ans = min(ans, size);
    return sum + 1;
}

int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}