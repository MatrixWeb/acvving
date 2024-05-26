// https://www.acwing.com/problem/content/870/
// 线性筛法
// 核心思想： 每个合数，只被自己的最小质因子筛出
#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt ++] = i;
        // 开始筛掉合数
        // 从小到大遍历质数
        for (int j = 0; primes[j] <= n / i; j++) {
            // 还没break之前，p_j是p_j * i的最小质因子
            st[primes[j] * i] = true;
            // 此时p_j是i的最小质因子。
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
    
    return 0;
}