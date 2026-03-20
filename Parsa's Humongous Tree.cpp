#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n][2];
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    vector<int> v[n];
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    int connections[n];
    for(int i = 0; i < n; i++) {
        if(v[i].size() == 1) {
            q.push(i);
        }
        connections[i] = v[i].size();
    }
    long long ans[n][2], cnt = 0;
    for(int i = 0; i < n; i++) ans[i][0] = ans[i][1] = 0;
    bool been[n];
    fill(been, been+n, 0);
    while(!q.empty()) {
        int f = q.front(); q.pop();
        if(been[f]) continue;
        been[f] = 1;
        vector<int> v1;
        for(int i = 0; i < v[f].size(); i++) {
            if(!been[v[f][i]]) {
                connections[v[f][i]]--;
                if(connections[v[f][i]] == 1) {
                    q.push(v[f][i]);
                }
            } else {
                v1.push_back(v[f][i]);
            }
        }
        long long mn = arr[f][0], mx = arr[f][1];
        for(auto x : v1) {
            ans[f][0] += max(abs(arr[x][0] - mn) + ans[x][0], abs(arr[x][1] - mn) + ans[x][1]);
            ans[f][1] += max(abs(arr[x][0] - mx) + ans[x][0], abs(arr[x][1] - mx) + ans[x][1]);
        }
        cnt = max({cnt, ans[f][0], ans[f][1]});
    }
    cout << cnt << endl;
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
