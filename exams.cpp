#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int,int>> v;
    while(n--) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    int mn = 0;
    for(int i = 0; i < v.size(); i++) {
        if(mn <= v[i].second) {
            mn = v[i].second;
        } else {
            mn = v[i].first;
        }
    }
    cout << mn << endl;
}
