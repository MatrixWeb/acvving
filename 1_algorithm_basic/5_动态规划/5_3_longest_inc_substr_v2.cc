// https://www.acwing.com/problem/content/898/
// 最长上升子序列2
// q[i] 长度为i子序列最后一个元素值，这个值越小越好。q序列严格单调递增
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int q[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        // 二分找到 q[r] < a[i] <= q[r+1]
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    cout << len << endl;
    return 0;
}