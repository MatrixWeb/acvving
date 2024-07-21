// https://www.acwing.com/problem/content/894/
// 台阶nim
// 先手必胜条件：奇数台阶数异或不为0
// 先把奇数台阶数异或变为0。然后对手从偶数台阶取，就对应放入下一个台阶。保持奇数台阶不变。
// 对手从奇数台阶取，就把奇数台阶数异或变为0
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i&1) res ^= x;
    }
    if (res) puts("Yes");
    else puts("No");
    return 0;
}