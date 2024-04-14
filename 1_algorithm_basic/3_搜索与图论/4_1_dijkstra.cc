/*
最短路算法汇总：
1、单源最段路
    （1）所有边权都是正数
      (1.1） 朴素Dijkstra算法 O(n^2) 适合稠密图
      (1.2) 堆优化版Dijskstra算法 O(mlogn) 适合m和n都是10^5
    (2) 存在负权边
      (2.1) Bellman-Ford O(nm) 边个数有限制场景
      (2.2) SPFA 一般O(m), 最坏O(nm)
2、多源汇最段路
  Floyd算法 O(n^3)
*/
// https://www.acwing.com/problem/content/851/
// 朴素版dijkstra算法
#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
            
        for (int j = 1; j <= n; j++) {
            dist[j] = min (dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m --) {
        int a, b, c;
        cin >> a >> b >> c;
        
        g[a][b] = min (g[a][b], c);
    }
    cout << dijkstra() << endl;
    
    return 0;
}