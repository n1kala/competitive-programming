#include <bits/stdc++.h>
using namespace std;

bool point(vector<int> &v, int i) {
    return (v[i] > v[i-1] and v[i] > v[i+1]) or (v[i] < v[i+1] and v[i] < v[i-1]);
}

int check(vector<int> &v, int i) {
    int ans = 0;
    if(i-1 > 0) {
        ans += point(v, i-1);
    }
    ans += point(v, i);
    if(i+1 < v.size()-1) {
        ans += point(v, i+1);
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> arr(n);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bool one = false, two = false, three = false;
        for(int i = 1; i < n-1; i++) {
            ans += point(arr, i);
        }
        for(int i = 1; i < n-1; i++) {
            int temp = arr[i];
            int v1 = check(arr, i);
            arr[i] = arr[i-1];
            int v2 = check(arr, i);
            arr[i] = arr[i+1];
            int v3 = check(arr, i);
            arr[i] = temp;
            if(v1 - v2 == 3) {
                three = two = one = true;
            } else if(v1 - v2 == 2) {
                two = one = true;
            } else if(v1 - v2 == 1) {
                one = true;
            }
            swap(v2, v3);
            if(v1 - v2 == 3) {
                three = two = one = true;
            } else if(v1 - v2 == 2) {
                two = one = true;
            } else if(v1 - v2 == 1) {
                one = true;
            }
        }
        ans -= three+two+one;
        cout << ans << endl;
    }
}
