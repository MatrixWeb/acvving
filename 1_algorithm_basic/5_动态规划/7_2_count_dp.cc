// https://www.acwing.com/problem/content/902/
// 整数划分第二种写法
// f[i][j] : 总和为i，总个数为j的方案数
// f[i-1][j - 1]: 最小值为1的情况，剔除一个1
// f[i-j][j]： 最小值>1的情况，整体减1
#include <bits/stdc++.h>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int f[N][N];

int main() {
    cin >> n;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i-1][j-1] + f[i-j][j]) % mod;
            
    int res = 0;
    for (int i = 1; i <= n; i++) res = (res + f[n][i]) % mod;
    
    cout << res << endl;
    
    return 0;
}