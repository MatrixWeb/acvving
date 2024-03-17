// https://www.acwing.com/problem/content/838/
// 并查集
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N];

// 返回x的祖宗
int find(int x) {
  // 对路径做压缩
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    
    while (m--) {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        if (*op == 'M') p[find(a)] = find(b);
        else {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}