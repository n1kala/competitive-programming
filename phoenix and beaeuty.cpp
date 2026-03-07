#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        int arr[n];
        bool same = true;
        set<int> st;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i and arr[i] != arr[i-1]) {
                same = false;
            }
            st.insert(arr[i]);
        }
        if(same) {
            cout << n << endl;
            while(n--) {
                cout << arr[0] << " ";
            }
            cout << endl;
            continue;
        } else if(k == 1 or st.size() > k) {
            cout << -1 << endl;
            continue;
        }
        cout << n*k << endl;
        for(int i = 0; i < n; i++) {
            for(auto &x : st) {
                cout << x << " ";
            }
            for(int j = st.size(); j < k; j++) {
                cout << n << " ";
            }
        }
        cout << endl;
    }
}
