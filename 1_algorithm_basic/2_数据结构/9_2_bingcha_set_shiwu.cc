// https://www.acwing.com/problem/content/242/
// 并查集食物链
#include <bits/stdc++.h>
using namespace std;

const int N = 50010;

int n, m;
// d[x]表示到父节点的距离
// 每次做完路径压缩，d[x]=x到根节点的距离。%3=0表示根节点同类，%3=1表示可以吃根节点，%3=2表示可以被根节点吃
// p数组是并查集。所有信息里面，具备关系的都放到统一集合里面，这样就可以根据d知道任意2个点之间的关系。
int p[N], d[N];

// 做完路径压缩后，x指向集合根节点
int find(int x) {
    if (p[x] != x) {
      // 先对父节点做路径压缩，然后更新d[x]
      int t = find(p[x]);
      d[x] += d[p[x]];
      // 计算距离，再更新x指向的节点
      p[x] = t;
    }
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    
    int res = 0;
    
    while(m --) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > n ||y > n) res ++;
        else {
            int px = find(x), py = find(y);
            if (t == 1) {
              // x和y是同类
                if (px == py && (d[x] - d[y]) % 3) res ++;
                else if (px != py) {
                    p[px] = py;
                    // x->px, y->py， px->py(但是这个距离？未知)
                    // x和y同类，合并后应该满足 （d[x] + ? - d[y])%3==0, 所以可以推导出 ？ = d[y] - d[x]
                    d[px] = d[y] - d[x];
                }
            } else {
              // x可以吃y，如果在同一个集合，先判断是否存在x比y的级别大1
                if (px == py && (d[x] - d[y] - 1) % 3) res ++;
                else if (px != py) {
                    p[px ] = py;
                    // 不在同一个集合
                    // x->px, y->py， px->py(但是这个距离？未知)
                    // x吃y，合并后应该满足 （d[x] + ? - d[y] - 1)%3==0 所以可以推导出 ？ = d[y] + 1 - d[x]
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}