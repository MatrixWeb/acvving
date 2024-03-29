// 贪心： 区间合并
// https://www.acwing.com/problem/content/805/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

void merge(vector<PII> &segs) {
    vector<PII> res;
    // 优先左端点，再按右端点
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg :segs) {
        if (ed < seg.first) {
            // 没有交集的情况
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}

int main() {
    int n ;
    cin >> n;
    vector<PII> segs;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}