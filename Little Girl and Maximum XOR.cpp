#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll l, r;
    cin >> l >> r;
    ll i = (1ll << 61);
    ll ans = 0;
    while((i&l) == (i&r) and i) {
        i >>= 1;
    }
    while(i) {
        ans += i;
        i >>= 1;
    }
    cout << ans << endl;
}
