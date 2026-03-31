#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<set<int>> v(n+1);
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    queue<int> q;
    q.push(1);
    int j = 1;
    map<int,int> been; been[1] = 1;
    while(!q.empty()) {
        int f = q.front(); q.pop();
        set<int> &st = v[f];
        int sz = j+st.size();
        sz = min(sz, n);
        for(j; j < sz; j++) {
            if(st.find(arr[j]) != st.end() and !been[arr[j]]) {
                st.erase(arr[j]);
                q.push(arr[j]);
                v[arr[j]].erase(f);
                //cout << arr[j] << endl;
                if(been[arr[j]] == false) {
                    for(auto x : v[arr[j]]) v[x].erase(arr[j]);
                }
                been[arr[j]] = true;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
