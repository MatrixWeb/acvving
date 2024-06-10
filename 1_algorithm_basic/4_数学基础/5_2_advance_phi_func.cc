// https://www.acwing.com/problem/content/876/
// 线性筛法求欧拉函数
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000010;

int primes[N], cnt;
int euler[N];
bool st[N];

void get_eulers(int n) {
    euler[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0) {
                // 根据欧拉函数公式
                // phi[N] = N(1-1/p1)(1-1/p2)...(1-1/pk)
                // 由于pj|i, 所以新增pj只会影响N的部分，不会影响后面部分。所以直接乘pj就行
                euler[t] = euler[i] * primes[j];
                break;
            }
            // 由于i不整除pj，所以新加入的pj需要把后面部分也乘进来
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    get_eulers(n);
    
    LL res = 0;
    for (int i = 1; i <= n; i++) res += euler[i];
    
    cout << res << endl;
    return 0;
}
