#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int arr[n];
    int xr = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        xr ^= arr[i];
    }
    if(xr == 0) {
        cout << "YES\n";
        return;
    }
    int xr1 = 0;
    for(int i = 0 ;i < n; i++) {
        xr1 ^= arr[i];
        if(xr1 == xr) {
            int xr2 = 0;
            for(int  j = n-1; j >= 0; j--) {
                xr2 ^= arr[j];
                if(xr2 == xr1) {
                    if(j > i) {
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";

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
