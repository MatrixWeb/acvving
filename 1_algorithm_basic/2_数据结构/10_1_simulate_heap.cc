// https://www.acwing.com/problem/content/841/
// 模拟堆
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

// ph表示第k个插入的元素下标是a
// hp表示下标为a的元素是第k个插入的
int h[N], ph[N], hp[N], cnt;

// 调整两个元素信息，两个索引数组也要跟着调整。
void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

// 向下调整
void down(int u) {
    int t = u;
    if (u * 2 <= cnt && h[u*2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}

// 向上调整
void up(int u) {
    while( u/2 && h[u] < h[u / 2]) {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}


int main() {
    int n, m = 0;
    cin >> n;
    while( n --) {
        char op[5];
        int k, x;
        cin >> op;
        if (!strcmp(op, "I")) {
            cin >> x;
            cnt ++;
            m++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        } else if (!strcmp(op, "PM")) {
            cout << h[1] << endl;
        } else if (!strcmp(op, "DM")) {
            heap_swap(1, cnt);
            cnt --;
            down(1);
        } else if (!strcmp(op, "D")) {
            cin >> k;
            k = ph[k];
            heap_swap(k, cnt);
            cnt --;
            up(k);
            down(k);
        } else {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}
