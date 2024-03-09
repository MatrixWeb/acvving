// https://www.acwing.com/problem/content/828/
// 单链表， 数组模拟
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

// 将x插到头结点
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx ++;
}

// 将x插到下标是k的点后面
void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}

// 将下标是k的点后面的点删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m;
    cin >> m;
    
    init();
    while(m --) {
        int k, x;
        char op;
        cin >> op;
        
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'D') {
            cin >> k;
            if (!k) head = ne[head];
            remove(k - 1);
        } else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}