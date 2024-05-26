// https://www.acwing.com/problem/content/869/
// 分解质因数
#include <bits/stdc++.h>

using namespace std;

void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while(x % i == 0) x /= i, s++;
            cout << i << ' ' << s << endl;
        }
    }
    // 最多只有一个大于根号n的质数，剩到最后这个
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main() {
    int n; 
    cin >> n;
    while( n--) {
        int x;
        cin >> x;
        divide(x);
    }
    return 0;
}