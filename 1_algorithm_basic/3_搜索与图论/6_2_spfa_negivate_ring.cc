// https://www.acwing.com/problem/content/854/
// spfa判断负环
#include <bits/stdc++.h>

using namespace std;

const int N = 2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    // 不需要初始化dist数组，因为需要负数来更新
    queue<int> q;
    // 从1出发有可能到不了，所以所有点都需要入队
    for (int i = 1; i <= n; i++) {
        st[i] = true;
        q.push(i);
    }
    
    while(q.size()) {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    
    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    if (spfa()) puts("Yes");
    else puts("No");
    
    return 0;
}
