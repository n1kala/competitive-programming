#include<bits/stdc++.h>
using namespace std;
#define MOD 100000000

// total footmen, total horsemen, consecutive footmen in the end, same on horsmen
int dp[101][101][11][11];

int main() {
    int n1,n2,k1,k2;
    cin >> n1 >> n2 >> k1 >> k2;
    // absolute base
    for(int i = 1; i <= 10; i++) dp[i][0][i][0] = 1;
    for(int i = 1; i <= 10; i++) dp[0][i][0][i] = 1;

    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            // if we have consecutive same type soldiers of amount i1
            // we must have added it next to i1-1 consecutive soldiers
            // or as a new type of soldier next to some j1 amount of others
            for(int i1 = 1; i1 <= k1; i1++) {
                dp[i][j][i1][0] = dp[i-1][j][i1-1][0];
                for(int j1 = 1; j1 <= k2; j1++) {
                    if(i1 == 1) {
                        dp[i][j][i1][0] += dp[i-1][j][0][j1];
                        dp[i][j][i1][0] %= MOD;
                    }
                }
            }
            for(int i1 = 1; i1 <= k2; i1++) {
                dp[i][j][0][i1] = dp[i][j-1][0][i1-1];
                for(int j1 = 1; j1 <= k1; j1++) {
                    if(i1 == 1) {
                        dp[i][j][0][i1] += dp[i][j-1][j1][0];
                        dp[i][j][0][i1] %= MOD;
                    }
                }
            }
        }
    }
    long long ans = 0;
    for(int i1 = 1; i1 <= k1; i1++) {
        ans += dp[n1][n2][i1][0];
    }
    for(int i1 = 1; i1 <= k2; i1++) {
        ans += dp[n1][n2][0][i1];
    }
    cout << ans%MOD << endl;
}
