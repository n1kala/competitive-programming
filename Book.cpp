#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<set<int>> pre(n+1);
    vector<vector<int>> post(n+1);
    vector<int> lvl(n+1, -1);
    set<pair<int,int>> q;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        if(k == 0) {
            q.insert({1,i+1});
            lvl[i+1] = 1;
        }
        while(k--) {
            int a; cin >> a;
            pre[i+1].insert(a);
            post[a].push_back(i+1);
        }
    }
    while(!q.empty()) {
        pair<int,int> p = *(q.begin()); q.erase(p);
        int f = p.second;
        for(auto &x : post[f]) {
            if(pre[x].find(f) != pre[x].end()) {
                pre[x].erase(f);
                if(pre[x].size() == 0) {
                    lvl[x] = lvl[f]+1-(x>f);
                    q.insert({lvl[x],x});
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(lvl[i] == -1) {
            cout << -1 << endl;
            return;
        }
        ans = max(ans, lvl[i]);
    }
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}
