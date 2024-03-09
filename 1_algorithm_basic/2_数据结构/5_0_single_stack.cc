// https://www.acwing.com/problem/content/832/
// 单调栈
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

// 求左边最近的比当前小的元素
// 栈内元素从小到大递增，且当前元素找完之后要操作入栈
int stk[N], tt;

int main() {
    int n;
    cin >> n;
    while(n --) {
        int x;
        cin >> x;
        while(tt && stk[tt] >= x) tt --;
        if (!tt) cout << "-1 ";
        else cout << stk[tt] << " ";
        stk[++tt] = x; 
    }
    return 0;
}