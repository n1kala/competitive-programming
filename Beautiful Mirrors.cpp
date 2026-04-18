#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 998244353

ll power(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b%2 == 0) {
            a *= a;
            a %= MOD;
            b /= 2;
        } else {
            ans *= a;
            ans %= MOD;
            b--;
        }
    }
    return ans;
}

ll inv(ll n) {
    return power(n, MOD - 2);
}

int main() {
    ll n; cin >> n;
    ll up = 1, inv100 = inv(100);
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        ll p; cin >> p;
        p = (p*inv100)%MOD;
        cnt += up;
        cnt %= MOD;
        up *= p;
        up %= MOD;
    }
    cout << cnt * inv(up) % MOD << endl;
}
