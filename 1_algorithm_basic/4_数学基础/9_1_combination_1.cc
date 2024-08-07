// https://www.acwing.com/problem/content/887/
// 求组合数。 利用C(a, b) = C(a-1, b) + C(a-1, b-1)
// 0 < a, b < 2000
#include <bits/stdc++.h>

using namespace std;

const int N = 2010, mod = 1e9 + 7;

int c[N][N];

void init() {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j <= i; j++)
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
}

int main() {
    int n;
    init();
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}