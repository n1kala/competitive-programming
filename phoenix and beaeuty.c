#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        int arr[n];
        bool same = true;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i and arr[i] != arr[i-1]) {
                same = false;
            }
        }
        if(same) {
            cout << n << endl;
            while(n--) {
                cout << arr[0] << " ";
            }
            cout << endl;
            continue;
        } else if(k == 1) {
            cout << -1 << endl;
            continue;
        }
        cout << k*n << endl;
        for(int i = 0; i < k; i++) {
            for(int j = 1; j <= n; j++) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}
