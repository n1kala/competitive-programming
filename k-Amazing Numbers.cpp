#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n], ans[n];
    int filled = 0;
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
        ans[i] = -1;
    }
    for(auto &x : mp) {
        vector<int> &v1 = x.second;
        int mx = 0;
        for(int i = 0; i < v1.size(); i++) {
            if(i == 0) {
                mx = max(mx, v1[i]);
            }
            if(i == v1.size()-1) {
                mx = max(mx, n - v1[i] -1);
            }
            if(i > 0){
                mx = max(mx, v1[i] - v1[i-1] - 1);
            }
        }
        for(int i = mx; i < n-filled; i++) ans[i] = x.first;
        filled = max(filled, n-mx);
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
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
