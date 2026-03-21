#include<bits/stdc++.h>
using namespace std;
bool been[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int arr[n];
    int cnt[n+1];
    fill(cnt, cnt+n+1, 0);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > n) arr[i] = 0;
        else cnt[arr[i]]++;
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(cnt[arr[i]] < arr[i]) arr[i] = 0;
        else if(!been[arr[i]] and arr[i] != 0) {
            v.push_back(arr[i]);
            been[arr[i]] = 1;
        }
    }
    int sz = v.size();
    int occ[sz][n];
    int indx[n+1];
    for(int i = 0; i < sz; i++) indx[v[i]] = i;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < sz; j++) {
            occ[j][i] = 0;
            if(i > 0) {
                occ[j][i] = occ[j][i-1];
            }
        }
        if(arr[i] != 0) {
            occ[indx[arr[i]]][i] ++;
        }
    }
    while(m--) {
        int l, r; cin >> l >> r;
        r--;l-=2;
        int occ1[sz], ans = 0;
        for(int i = 0; i < sz; i++) occ1[i] = occ[i][r];
        if(l >= 0) {
            for(int i = 0; i < sz; i++) {
                occ1[i] -= occ[i][l];
            }
        }
        for(int i = 0; i < sz; i++) {
            if(occ1[i] == v[i]) ans++;
        }
        cout << ans << endl;
    }
}
