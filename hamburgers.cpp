#include<bits/stdc++.h>
using namespace std;
int main() {

    string s; cin >> s;
    long long n1,n2,n3; cin >> n1 >> n2 >> n3;
    long long p1,p2,p3; cin >> p1 >> p2 >> p3;
    long long ru; cin >> ru;

    long long h1 = 0,h2 =0 ,h3 = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'B') h1++;
        else if(s[i] == 'S') h2++;
        else h3++;
    }
    long long l = 0, r = 10000000000000;
    while(l < r-1) {
        long long m = (l+r)/2;
        long long a1 = h1 * m, a2 = h2 *m, a3 = h3*m;
        long long cnt = 0;
        a1 -= n1;
        a2-=n2;
        a3-=n3;
        if(a1 > 0) cnt += p1*a1;
        if(a2 > 0) cnt += p2*a2;
        if(a3 > 0) cnt += p3*a3;
        if(cnt <= ru) l = m;
        else r = m;
    }
    cout << l << endl;
}
