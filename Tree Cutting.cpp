#include <bits/stdc++.h>
using namespace std;

bool check(int m, int k, int n, vector<vector<int>> &e, vector<int> &leaves) {
    queue<int> q;
    int cnt[n+1];
    bool been[n+1];
    fill(cnt, cnt+n+1, 1);
    fill(been, been+n+1, 0);
    int children[n+1];
    fill(children, children+n+1, 0);
    for(int i = 1; i <= n; i++) {
        children[i] = e[i].size();
    }
    for(auto &x : leaves) {
        q.push(x);
        children[x] = 0;
    }
    bool stopCutting = false;
    while(!q.empty()) {
        int f = q.front(); q.pop();
        if(been[f]) continue;
        been[f] = 1;
        if(cnt[f] >= m and !stopCutting) {
            if(children[f] > 0) {
                k -= children[f];
                if(k <= 0) {
                    stopCutting = true;
                }
                for(auto &x : e[f]) {
                    if(!been[x]) {
                        children[x]--;
                        if(children[x] == 1)
                            q.push(x);
                    }
                }
            }
            continue;
        }
        bool ended = cnt[f] < m;
        for(auto &x : e[f]) {
            if(been[x]) continue;
            ended = false;
            children[x]--;
            if(children[x] == 1) q.push(x);
            cnt[x] += cnt[f];
        }
        if(ended) {
            return false;
        }
    }

    return k <= 0;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> e(n+1);
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<int> leaves;
    for(int i = 1; i <= n; i++)
        if(e[i].size() == 1)
            leaves.push_back(i);
    int l = 1, r = n;
    while(l < r-1) {
        int m = (r+l)/2;
        if(check(m, k, n, e, leaves)) l = m;
        else r = m;
    }
    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}
