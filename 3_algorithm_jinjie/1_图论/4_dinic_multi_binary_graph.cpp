// dinic解决二分图多重匹配问题
// https://www.acwing.com/problem/content/2181/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 430, M = (150 * 270 + N) * 2, INF = 1e8;

int m, n, S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
    int hh = 0, tt = 0;
    memset(d, -1, sizeof d);
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while(hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int ver = e[i];
            if (d[ver] == -1 && f[i]) {
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T) return true;
                q[++tt] = ver;
            }
        }
    }
    return false;
}

int find(int u, int limit) {
    if (u == T) return limit;
    int flow = 0;
    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i]) {
            int t = find(ver, min(f[i], limit - flow));
            if (!t) d[ver] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}

int dinic() {
    int r = 0, flow;
    while(bfs()) while(flow = find(S, INF)) r += flow;
    return r;
}

int main() {
    cin >> m >> n;
    S = 0, T = m + n + 1;
    memset(h, -1, sizeof h);
    int tot = 0;
    for (int i = 1; i<= m; i++) {
        int c;
        cin >> c;
        add(S, i, c);
        tot += c;
    }
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        add(m + i, T, c);
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            add(i, m + j, 1);
    
    if (dinic() != tot) cout << "0" << endl;
    else {
        cout << 1 << endl;
        for (int i = 1; i<= m;i++) {
            for (int j = h[i]; ~j; j = ne[j])
                if (e[j] > m && e[j] <= m + n && !f[j])
                    cout << e[j] - m << " ";
        cout << endl;
        }
    }
    return 0;
}