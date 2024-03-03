// 逆序对个数
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int a[N], tmp[N];

LL merge_sort(int q[], int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    
    // 合并成一个数组的时候算逆序对
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else {
            res += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j ++];
    for ( i = l, j = 0; i <= r; i ++, j++) q[i] = tmp[j];
    return res;
} 

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    cout << merge_sort(a, 0, n - 1) << endl;
    return 0;
}