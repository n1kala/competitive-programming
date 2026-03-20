#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m; cin >> n >> m;
    map<pair<int,int>, bool> mp;
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        mp[{a,b}] = 1;
    }
    int arr[n];
    for(int i = 0; i < n; i++) arr[i] = i+1;
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 and mp[{arr[j-1], arr[j]}]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
        if(i > j and mp[{arr[j], arr[j+1]}]) {
            cout << -1 << endl;
            return;
        }
    }
    for(auto x : arr) cout << x << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
}
