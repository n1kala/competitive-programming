#include <bits/stdc++.h>
using namespace std;

#define ll long long


void bitcount(int i, int d[][20], int sq, int * arr) {
    int cur[20];
    fill(cur, cur+20, 0);
    for(int j = i-1; ; j--) {
        for(int l = 0; l < 20; l++) {
            if((1 << l) & arr[j]) {
                cur[l]++;
            }
        }
        if(j%sq == 0) {
            for(int l = 0; l < 20; l++) {
                d[j][l] = cur[l];
            }
            break;
        }
    }
}

/*
    solution is with sqrt decomposition.
    idea is that after decomposing, each
    sqrt position holds bitset of elements
    on its right, until next sqrt. they
    also hold changes that happened to them
    with xor.
*/
void solution() {
    int n;
    cin >> n;
    int arr[n], d[n][20];
    int sq = sqrt(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(i%sq == 0) {
            if(i == 0 and n > 1) continue;
            bitcount(i,d,sq,arr);
        }
        if(i == n-1) {
            bitcount(i+1, d, sq, arr);
        }
    }

    int m; cin >> m;
    while(m--) {
        int t,l,r; cin >> t >> l >> r;
        l--;r--;
        vector<int> v;
        for(int i = (l+sq-1)/sq*sq; i < r; i+=sq) {
            v[i].push_back(i);
        }
        if(t == 1) {

        } else {
            int x; cin >> x;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);   cin.tie(0);   cout.tie(0);
    int t = 1; //cin >> t;
    while(t--)
        solution();
}

