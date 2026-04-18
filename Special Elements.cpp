#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool mp[n+1] = {0};
    for(int i = 2; i <= n; i++) {
        int sum = 0;
        for(int j = 0; j < i; j++) {
            sum += arr[j];
        }
        if(sum <= n)
            mp[sum] = 1;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            sum -= arr[j-i];
            if(sum <= n)
                mp[sum] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(mp[arr[i]]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1; cin >> t;
    while(t--) {
        solve();
        cout << endl;
    }
}
