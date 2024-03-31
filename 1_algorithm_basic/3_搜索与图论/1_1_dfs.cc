// https://www.acwing.com/problem/content/844/
// 排列数字 dfs算法
#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n;
int path[N];

void dfs(int u, int state) {
    if (u == n) {
        for (int i = 0; i < n; i++) cout << path[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!(state >> i & 1)) {
            path[u] = i + 1;
            dfs(u + 1, state + (1 << i));
        }
    }
}

int main() {
    cin >> n;
    dfs(0, 0);
    return 0;
}