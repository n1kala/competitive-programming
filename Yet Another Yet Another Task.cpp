#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 1; i < 31; i++) {
        int sum = 0;
        int mx = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] > i) {
                sum = 0;
            } else {
                sum += arr[j];
                if(sum < 0) {
                    sum = 0;
                }
            }
            mx = max(mx, sum);
        }
        ans = max(mx - i, ans);
    }
    cout << ans << endl;
}
