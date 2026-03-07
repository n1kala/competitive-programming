#include <bits/stdc++.h>
using namespace std;
int arr[200001][3];
vector<int> v[200001],p(200001);
int have[200001][2], need[200001][2];
int ans;
void dfs(int par, int cur, int mn) {
    mn = min(mn, arr[cur][0]);
    arr[cur][0] = mn;
    if(arr[cur][1] != arr[cur][2]) {
        have[par][0] += arr[cur][1] == 0;
        have[par][1] += arr[cur][1] == 1;

        need[par][0] += arr[cur][2] == 0;
        need[par][1] += arr[cur][2] == 1;
    }

    for(auto &x : v[cur]) {
        dfs(cur, x, mn);
    }
}

void solve(int cur) {
    int hv0 = have[cur][0], hv1 = have[cur][1];
    int nd0 = need[cur][0], nd1 = need[cur][1];
    int a = min(hv0,nd0), b = min(hv1,nd1);
    ans += (a + b) * arr[cur][0];
    if(cur == 1) return;
    have[p[cur]][0] += have[cur][0] - a;
    have[p[cur]][1] += have[cur][1] - b;
    need[p[cur]][0] += need[cur][0] - a;
    need[p[cur]][1] += need[cur][1] - b;
    solve(p[cur]);
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i+1][0] >> arr[i+1][1] >> arr[i+1][2];
    }
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        p[b] = a;
    }
    dfs(0, 1, arr[1][0]);
    for(int i = 0; i < n; i++) {
        if(v[i+1].size() == 0) {
            solve(i+1);
        }
    }
    cout << ans << endl;
}
