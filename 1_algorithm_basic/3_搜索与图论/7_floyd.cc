// floyd算法，核心基于动态规划
// https://www.acwing.com/problem/content/856/
#include <bits/stdc++.h>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i<= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    cin >> n >> m >> Q;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
            
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    
    floyd();
    
    while(Q--) {
       int a, b;
       cin >> a >> b;
       int t= d[a][b];
       
       if (t > INF / 2) puts("impossible");
       else cout << t << endl;
    }
    return 0;
}