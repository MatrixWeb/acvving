// https://www.acwing.com/problem/content/872/
// 标准因式分解求约数个数
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 110, mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    unordered_map<int, int> primes;
    
    while(n--) {
        int x;
        cin >> x;
        for (int i = 2; i <= x/i; i++) {
            while(x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1) primes[x]++;
    }
    LL res = 1;
    for (auto p : primes) res = res * (p.second + 1) % mod;
    
    cout << res << endl;
    
    return 0;
}