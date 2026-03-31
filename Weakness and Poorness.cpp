#include <bits/stdc++.h>
using namespace std;

long double solve(long double * arr, int n, long double x) {
    long double arr1[n];
    for(int i = 0; i < n; i++) {
        arr1[i] = arr[i]-x;
    }
    long double dp,ndp;
    dp = arr1[0];
    ndp = arr1[0];
    long double mx = abs(arr1[0]);
    for(int i = 1; i < n; i++) {
        dp = max(arr1[i], dp+arr1[i]);
        ndp = min(arr1[i], ndp+arr1[i]);
        mx = max({mx, abs(dp), abs(ndp)});
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    long double arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    long double a=-10001,b=10001, ans = 4000000001;
    while(a < b-0.0000000000001) {
        long double m = (a+b)/2;
        long double m1 = m+0.0000000000001;
        long double ans1 = solve(arr, n, m);
        long double ans2 = solve(arr, n, m1);
        ans = min({ans,ans1,ans2});

        if(ans1 > ans2) {
            a = m;
        } else {
            b = m;
        }
    }
    cout << setprecision(16) << ans << endl;
}
