// https://www.acwing.com/problem/content/868/
// 试除法判断素数
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    // 推荐这个写法，sqrt每次调用浪费，i*i可能溢出
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    while(n --) {
        int x;
        cin >> x;
        if (is_prime(x)) cout << "Yes" << endl;
        else puts("No");
    }
    return 0;
}