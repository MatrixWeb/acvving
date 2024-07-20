// https://www.acwing.com/problem/content/893/
// nim game 1
// a1^...^an = 0 先手必败。 ！=0 先手必胜。
// 要怎么取： 设a1^...^an= x, 设最高k位为1。则指数有一个aik位为1。取ai - ai^x个。
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int main() {
    int n;
    cin >> n;
    int res  = 0;
    while(n--) {
        int x;
        cin >> x;
        res ^= x;
    }
    if (res) puts("Yes");
    else puts("No");
    
    return 0;
}