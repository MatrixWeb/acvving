// https://www.acwing.com/problem/content/885/
// 高斯消元
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const double eps = 1e-8;

int n;
double a[N][N];

int gauss() { // 高斯消元，答案存于a[i][n]中，0 <= i < n
    int c, r;
    for (c = 0, r = 0; c < n; c++) {
        int t = r;
        for (int i = r; i < n; i++) { // 找绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        }
        if (fabs(a[t][c]) < eps) continue;
        
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]); // 将绝对值最大的行换到最顶端
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c]; // 将当前行的首位变成1
        for (int i = r + 1; i < n; i++) { // 用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];
        }
        r++;
    }
    if (r < n) {
        for(int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return 2; // 无解
        return 1; // 有无穷多组解
    }
    for (int i = n - 1; i >= 0; i--) 
        for (int j = i + 1; j < n;j++)
            a[i][n] -= a[i][j] * a[j][n];
    return 0; // 有唯一解
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++) {
            cin >> a[i][j];
        }
    int t = gauss();
    if (t == 2) cout << "No solution" << endl;
    else if (t == 1) cout << "Infinite group solutions" << endl;
    else {
        for (int i = 0; i < n; i++) {
            printf("%.2lf\n", a[i][n]);
        }
    }
    return 0;
}