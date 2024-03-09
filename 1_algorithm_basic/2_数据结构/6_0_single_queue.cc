// https://www.acwing.com/problem/content/156/
// 单调队列
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
// q保持数组下标
int a[N], q[N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int hh = 0, tt = -1;
    // 对头保持最小值，当前元素要入队，所以队列元素是单调递增的
    for (int i = 0; i < n; i++) { 
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << " ";
    }
    puts("");
    hh = 0, tt = -1;
    // 对头保持最大值，当前元素要入队，所以队列元素是单调递减
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << " ";
    }
    cout << endl;
    return 0;
}