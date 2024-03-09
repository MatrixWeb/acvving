// https://www.acwing.com/activity/content/code/content/40069/
// 双指针
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    // 有单调性
    for (int i = 0, j = m - 1; i < n; i++) {
        // 找到 a[i] + b[j] >= x 最左边的点
        while (j >= 0 && a[i] + b[j] > x) j--;
        if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;
    }
    return 0;
}