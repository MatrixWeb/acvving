// https://www.acwing.com/problem/content/803/
// 二进制lowbit(1000100) = 100, 返回最后一位1的位置
#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        int x, s = 0;
        cin >> x;
        for (int i = x; i; i -= lowbit(i)) s++;
        cout << s << " ";
    }
    return 0;
}