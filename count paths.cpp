#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix &A, const Matrix &B, int n) {
    Matrix C(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            if(A[i][k] == 0) continue;
            for(int j = 0; j < n; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix A, long long k, int n) {
    Matrix res(n, vector<long long>(n, 0));

    // identity matrix
    for(int i = 0; i < n; i++) res[i][i] = 1;

    while(k) {
        if(k & 1) res = multiply(res, A, n);
        A = multiply(A, A, n);
        k >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    Matrix A(n, vector<long long>(n, 0));

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        A[a][b] = 1;
    }

    Matrix Ak = power(A, k, n);

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = (ans + Ak[i][j]) % MOD;
        }
    }

    cout << ans << '\n';
}
