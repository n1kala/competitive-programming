#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long gl[n],gr[n],sl[n],sr[n],fg[n],fs[n];
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() and arr[st.top()] <= arr[i]) st.pop();
        gl[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() and arr[st.top()] < arr[i]) st.pop();
        gr[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = 0; i < n; i++) {
        while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
        sl[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() and arr[st.top()] > arr[i]) st.pop();
        sr[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        fg[i] = gl[i]*gr[i];
        fs[i] = sl[i]*sr[i];
        ans += fg[i]*arr[i];
        ans -= fs[i]*arr[i];
    }
    cout << ans << endl;
}
