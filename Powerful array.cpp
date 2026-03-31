#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 200001;

int n, t;
int a[MAXN];
ll ans[MAXN];
int cnt[1000001];

struct Query {
    int l, r, idx;
};

int block;

bool cmp(Query A, Query B) {
    if (A.l / block != B.l / block)
        return A.l < B.l;
    return A.r < B.r;
}

ll cur = 0;

void add(int x) {
    cur += (2LL * cnt[x] + 1) * x;
    cnt[x]++;
}

void remove(int x) {
    cur -= (2LL * cnt[x] - 1) * x;
    cnt[x]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<Query> q(t);
    for (int i = 0; i < t; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].idx = i;
    }

    block = sqrt(n);

    sort(q.begin(), q.end(), cmp);

    int L = 1, R = 0;

    for (auto &qr : q) {
        while (R < qr.r) add(a[++R]);
        while (R > qr.r) remove(a[R--]);
        while (L < qr.l) remove(a[L++]);
        while (L > qr.l) add(a[--L]);

        ans[qr.idx] = cur;
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << '\n';
}
