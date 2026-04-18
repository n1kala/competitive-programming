#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        bool ans = k%2 == 0;
        for(int i = 0; i < n-k; i++) {
            if(s[i] == '0' and s[i+k] == '1') ans = false;
            if(s[i] == '1' and s[i+k] == '0') ans = false;
            if(s[i] == '?') s[i] = s[i+k];
            if(s[i+k] == '?') s[i+k] = s[i];
        }
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0')a++;
            else if(s[i] == '1')b++;
            if(i >= k) {
                if(s[i-k] == '0') a--;
                else if(s[i-k] == '1') b--;
            }
            if(a > k/2 or b > k/2) ans = false;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
