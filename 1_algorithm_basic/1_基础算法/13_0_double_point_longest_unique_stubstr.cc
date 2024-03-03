// 双指针最长连续不重复子串
// https://www.acwing.com/problem/content/801/
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n;
// s数组类似map，记录元素计数
int q[N], s[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    
    int res = 0;
    // 以i为终点的子串
    for (int i = 0, j = 0; i < n; i++) {
        s[q[i]] ++;
        // 保证加入的元素个数不会超过1
        while(j < i && s[q[i]] > 1)s[q[j++]] --;
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}