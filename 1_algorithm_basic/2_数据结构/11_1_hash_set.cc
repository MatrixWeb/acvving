// 开放寻址法
#include <bits/stdc++.h>

using namespace std;

// N一般开元素个素的2-3倍
// null 超过10^9
const int N = 2e5 +3, null = 0x3f3f3f3f;

int h[N];

// 返回x应该插入的位置
int find(int x) {
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x) {
        t++;
        if (t == N) t = 0;
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    memset(h, 0x3f, sizeof h);
    
    while(n --) {
        char op[2];
        int x;
        cin >> op >> x;
        
        if (*op == 'I') h[find(x)] = x;
        else {
            if (h[find(x)] == null) puts("No");
            else {
                puts("Yes");
            }
        }
    }
    return 0;
}