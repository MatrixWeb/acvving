// https://www.acwing.com/problem/content/340/
// 数位DP
// 
#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int get(vector<int> num, int l, int r) {
    int res = 0;
    for (int i = l; i >= r; i--) res = res * 10 + num[i];
    return res;
}

int power10(int x) {
    int res = 1;
    while(x --) res *= 10;
    return res;
}

// 统计 1～n里面x的个数
int count(int n, int x) {
    if (!n) return 0;
    
    vector<int> num;
    while(n) {
        num.push_back(n % 10);
        n /= 10;
    }
    n = num.size();
    
    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i--) {
      // 1在第4位的个数统计：
      // 1 <= xxx1yyy <= abcdefg
      // (1) xxx = 0 ~ abc - 1, yyy 可取000 ～ 999， 一共 abc * 10
        if (i < n - 1) {
            res += get(num, n - 1, i + 1) * power10(i);
            // 统计为0的时候xxx只能取1 ～ abc - 1
            if (!x) res -= power10(i);
        }
      // （2） xxx = abc
      // (2.1) d < 1, abc1yyy > abc0efg, 为0
      // （2.2） d == 1, yyy = 000 ~ efg, 为efg + 1
      // (2.3) d > 1, yyy = 000 ~ 999, 1000 
        if (num[i] == x) res += get(num, i - 1, 0) + 1;
        else if (num[i] > x) res += power10(i);
    }
    return res;
}

int main() {
    int a, b;
    while(cin>> a >> b, a) {
        if (a > b) swap(a, b);
        for (int i = 0; i <= 9; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }
    return 0;
}