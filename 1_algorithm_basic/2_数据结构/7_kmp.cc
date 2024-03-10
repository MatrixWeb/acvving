// https://www.acwing.com/problem/content/833/
// kmp字符串匹配算法
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
int ne[N];
char s[M], p[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;
    
    // 求next数组，利用已求出来的。j代表目前已匹配点，j+1是当前跟i匹配的模式串点
    // next数组含义，当在j发现不匹配的时候 j = ne[j]，因为ne[1..ne[j]] = ne[j - ne[j] + 1 ... j] 存在最大的公共前后缀，所以可以按这个进行移动
    // 每次移动后看下一个点是否能跟p[i]匹配上，如果匹配上，就找到i对应的最长前缀位置。如果匹配不上，继续这个过程
    for (int i = 2, j = 0; i <= n; i++) {
        while(j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
    
    // 匹配过程。j是在模式串已经匹配点。
    // 当j+1发生失效的时候，利用next数组的公共前后缀信息，移动j = ne[j]，观察下一个点能否匹配上
    // 匹配上就移动j，继续后面的匹配，不行的话就继续递推这个过程。
    for (int i = 1, j = 0; i <= m; i++) {
        while(j && s[i] != p[j + 1])j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            cout << i - n << " ";
            j = ne[j];
        }
    }
    return 0;
}