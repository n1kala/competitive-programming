#include<bits/stdc++.h>
using namespace std;
bool been[100001];
int main() {
    int n,m; cin >> n >> m;
    vector<set<int>> edges(n+1);
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    set<int> st;
    for(int i = 1; i <= n; i++) st.insert(i);
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        if(been[i]) continue;
        been[i] = true;
        st.erase(i);
        queue<int> q;
        for(auto j = st.begin(); j != st.end(); ) {
            if(*j >= i) break;
            if(been[*j] == false and edges[i].find(*j) == edges[i].end()) {
                q.push(*j);
                been[*j] = 1;
                j = st.erase(j);
            } else {
                j++;
            }
        }
        while(!q.empty()) {
            int f = q.front(); q.pop();
            if(st.size() == 0) break;
            for(auto j = st.begin(); j != st.end(); ) {
                if(*j >= i) break;
                if(been[*j] == false and edges[f].find(*j) == edges[f].end()) {
                    q.push(*j);
                    been[*j] = true;
                    j = st.erase(j);
                } else {
                    j++;
                }
            }
        }
        if(st.size() == 0) break;
        ans++;
    }
    cout << ans << endl;
}
