// 拉链法处理哈希表
#include <bits/stdc++.h>

using namespace std;

// 最好取一个质数
const int N = 1e5 +3;

int h[N], e[N], ne[N], idx;

// 每个位置都是一个链表
void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    // 底层数组存的是链表头指针
    h[k] = idx ++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x)
            return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    // -1就是全部都是1，最后每个元素也是-1
    memset(h, -1, sizeof h);
    
    while(n --) {
        char op[2];
        int x;
        cin >> op >> x;
        
        if (*op == 'I') insert(x);
        else {
            if (find(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}