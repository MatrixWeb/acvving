// https://www.acwing.com/problem/content/145/
// trie数查找最大异或对
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 3100010;

int n;
int a[N], son[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int &s = son[p][x >> i & 1];
        if (!s) s = ++idx;
        p = s;
    }
}

int search(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int s = x >> i & 1;
        if (son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        } else {
            p = son[p][s];
        }
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    // 利用trie树对暴力做法优化
    for (int i = 0; i < n; i++) res = max(res, search(a[i]));
    
    cout << res << endl;
    
    return 0;
}