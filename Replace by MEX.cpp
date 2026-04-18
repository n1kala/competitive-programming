#include <bits/stdc++.h>
using namespace std;

int findmex(int * arr, int n) {
    vector<bool> seen(n + 1, false);
    for (int i = 0; i < n; i++) seen[arr[i]] = true;
    for (int i = 0; i <= n; i++) {
        if (!seen[i]) return i;
    }
    return n;
}

void solve() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans;

    while (true) {
        int f = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] != i) {
                f = i;
                break;
            }
        }
        if (f == -1) break;
        int m = findmex(arr, n);
        if (m < n) {
            arr[m] = m;
            ans.push_back(m + 1);
        } else {
            arr[f] = m;
            ans.push_back(f + 1);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}
