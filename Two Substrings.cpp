#include<bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    bool case1 = 1, case2 = 1;
    int indx1 = -1, indx2 = -1;
    for(int i = 0; i < s.length()-1; i++) {
        if(indx1 == -1 and s[i] == 'A') {
            if(s[i+1] == 'B') {
                indx1 = i;
            }
        }
        if(s[i] == 'B' and s[i+1] == 'A') {
            indx2 = i;
        }
    }
    if(indx1 != -1 and indx2 != -1 and indx1 != indx2-1 and indx1 != indx2+1) {
        cout << "YES\n";
    } else {
        indx1 = indx2 = -1;
        for(int i = 0; i < s.length()-1; i++) {
            if(s[i] == 'A') {
                if(s[i+1] == 'B') {
                    indx1 = i;
                }
            }
            if(indx2 == -1 and s[i] == 'B' and s[i+1] == 'A') {
                indx2 = i;
            }
        }
        if(indx1 != -1 and indx2 != -1 and indx1 != indx2-1 and indx1 != indx2+1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
