#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> children(200001), temp(200001), levels(200001);
int n;
int parent[200001];
int price[200001];
int level[200001];
bool number[200001];
bool desire[200001];
int ones[200001];
int onesDesired[200001];
int zeros[200001];
int zerosDesired[200001];
bool been[200001];
long long answer = 0;

bool checkMatch(int cur) {
    return number[cur] == desire[cur];
}

void increaseCounts(int cur) {
    ones[cur] += number[cur] == 1;
    zeros[cur] += number[cur] == 0;
    onesDesired[cur] += desire[cur] == 1;
    zerosDesired[cur] += desire[cur] == 0;
}

void countOnesZerosAndMatches(int cur) {
    if(!checkMatch(cur)) {
        increaseCounts(cur);
    }
}

void matchAndRedirect(int cur) {
    // basecase
    if(cur == 1) {
        return;
    }

    // we have more zeros than we can handle, so we redirect them to parent
    if(zeros[cur] > zerosDesired[cur]) {
        zeros[parent[cur]] += zeros[cur] - zerosDesired[cur];
        zeros[cur] = zerosDesired[cur];
    }

    // same but on ones
    if(ones[cur] > onesDesired[cur]) {
        ones[parent[cur]] += ones[cur] - onesDesired[cur];
        ones[cur] = onesDesired[cur];
    }

    // we also move desires up
    if(zerosDesired[cur] > zeros[cur]) {
        zerosDesired[parent[cur]] += zerosDesired[cur] - zeros[cur];
        zerosDesired[cur] = zeros[cur];
    }

    if(onesDesired[cur] > ones[cur]) {
        onesDesired[parent[cur]] += onesDesired[cur] - ones[cur];
        onesDesired[cur] = ones[cur];
    }
}

void countAnswer(int cur) {
    // now we know exactly how much should we match with current node's price
    long long currentPrice = price[cur];
    long long currentOnes = onesDesired[cur], currentZeroes = zerosDesired[cur];
    long long cost = currentPrice*(currentOnes + currentZeroes);
    answer += cost;
}

int main() {
    cin >> n;

    int cntl = 0, cntr = 0;
    for(int i = 0; i < n; i++) {
        cin >> price[i+1] >> number[i+1] >> desire[i+1];
        cntl += number[i+1] == 1;
        cntr += desire[i+1] == 1;
    }

    if(cntl != cntr) {
        cout << -1 << endl;
        return 0;
    }

    // saving edges to remember them go from root to leaves later
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        temp[a].push_back(b);
        temp[b].push_back(a);
    }

    // if parent is cheaper than child, its logical to redirect every
    // child to the parent. to do this we just change child's price and
    // not actually redirect anything to save time
    queue<int> q; q.push(1);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        been[cur] = 1;
        if(!level[cur]) {
            level[cur] = level[parent[cur]] + 1;
            levels[level[cur]].push_back(cur);
        }
        for(auto &x : temp[cur]) {
            if(been[x]) continue;
            been[x] = 1;
            children[cur].push_back(x);
            parent[x] = cur;
            price[x] = min(price[x], price[cur]);
            q.push(x);
        }
    }

    // now we start from leaves, match all we can in current node and
    // redirect rest to parent. in short we just change parent of the
    // ones that we could not match. but this would be too costy, so
    // instead of changing parents and checking if it matches, we
    // store total amount of ones and zeros and matches under each
    // node and then we only redirect numbers and never change actual
    // parents of any node
    for(int i = 1; i <= n; i++) {
        countOnesZerosAndMatches(i);
    }

    for(int i = n; i > 1; i--) {
        for(auto &x : levels[i]) {
            matchAndRedirect(x);
        }
    }

    // finally we count answer, since we know how many should we
    // shuffle for each node and what will it cost
    for(int i = 1; i <= n; i++) {
        countAnswer(i);
    }

    cout << answer << endl;

}
