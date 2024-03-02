// 前缀和算法
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    // 固定公式 s[i] = s[i - 1] + a[i]; s[0] = 0;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    
    while(m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}