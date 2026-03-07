#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solution() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int sq = sqrt(n);
    int bits[20]; fill(bits, bits+20, 0);
    int sums[n][20];
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < 20; j++) {
            if(arr[i] & (1 << j)) {
                bits[j]++;
            }
        }
        if(i%sq == 0) {
            for(int j = 0; j < 20; j++) {
                sums[i][j] = bits[j];
                bits[j] = 0;
            }
        }
    }
    vector<int> xors(n, 0);
    int m; cin >> m;
    while(m--) {
        int t,l,r; cin >> t >> l >> r;
        l--; r--;
        if(t == 1) {
            ll ans = 0;
            int i = (l + sq - 1) / sq * sq;
            if(i <= r) {
                int indx = i - sq;
                for(int k = l; k < i; k++) {
                    ans += arr[k]^xors[indx];
                }
                for(; i+sq <= r; i += sq) {
                    for(int j = 0; j < 20; j++) {
                        ll sm = 0;
                        if(xors[i] & (1 << j)) {
                            sm = sq - sums[i][j];
                        } else {
                            sm = sums[i][j];
                        }
                        sm *= (1 << j);
                        ans += sm;
                    }
                }
                for(int k = i; k <= r; k++) {
                    ans += arr[k]^xors[i];
                }
            } else {
                int indx = l - (l%sq);
                for(; l <= r; l++) {
                    ans += arr[l]^xors[indx];
                }
            }
            cout << ans << endl;
        } else {
            int x; cin >> x;
            int i = (l + sq - 1) / sq * sq;
            if(i <= r) {
                int indx = i - sq;
                int xr = xors[indx]^x;
                for(int k = i-sq; k < i; k++) {
                    if(k < 0) break;
                    int tmp = arr[k];
                    if(k >= l) {
                        arr[k] = arr[k]^xr;
                    } else {
                        arr[k] = arr[k]^xors[indx];
                    }
                    for(int f = 0; f < 20; f++) {
                        if(tmp & (1 << f)) sums[indx][f]--;
                        if(arr[k] & (1 << f)) sums[indx][f]++;
                    }
                    if(k == i-1) xors[indx] = 0;
                }
                for(; i+sq-1 <= r; i += sq) {
                    xors[i] ^= x;
                }
                xr = xors[i]^x;
                for(int k = i; k < i+sq; k++) {
                    if(k >= n) break;
                    int tmp = arr[k];
                    if(k <= r) {
                        arr[k] = arr[k]^(xr);
                    } else {
                        arr[k] = arr[k]^xors[i];
                    }
                    for(int f = 0; f < 20; f++) {
                        if(tmp & (1 << f)) sums[i][f]--;
                        if(arr[k] & (1 << f)) sums[i][f]++;
                    }
                    if(k == i+sq-1 or k == n-1) {
                        xors[i] = 0;
                    }
                }
            } else {
                int indx = l - (l%sq);
                int k = indx;
                for(; k < i; k++) {
                    int tmp = arr[k];
                    if(k >= l and k <= r) {
                        arr[k] = arr[k]^(xors[indx]^x);
                    } else {
                        arr[k] = arr[k]^xors[indx];
                    }
                    for(int f = 0; f < 20; f++) {
                        if(tmp & (1 << f)) sums[indx][f]--;
                        if(arr[k] & (1 << f)) sums[indx][f]++;
                    }
                    if(k == i-1) {
                        xors[indx] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);   cin.tie(0);   cout.tie(0);
    int t = 1; //cin >> t;
    while(t--)
        solution();
}

