#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

/*
Asymptotic Analysis

Time Complexity = O(N^2 + N*k + Max(O(N * Q), O(N * k)))
Space Complexity = O(N^2 + N*k)

*/

/*

Since Timestamp is sequential and increasing
There is no possibility of tie.
Therefore, No need to handle critical messages differently.

*/

void addMessage(int mId, int u, int sender, int k, vector<deque<pii>>& msgs) {
    // O(1) Time

    if(msgs[u].size() == k) {
        msgs[u].pop_front();
    }
    msgs[u].push_back({mId, sender});
}

void remMessage(int u, int sender, vector<deque<pii>>& msgs) {
    // O(k)
    for(auto it = msgs[u].begin(); it != msgs[u].end(); ) {
        if((*it).second == sender) {
            it = msgs[u].erase(it);
        } else {
            it++;
        }
    }
}

void solve() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<vector<int>> adjMat(n + 1, vector<int>(n + 1)); // O(N^2) Memory
    vector<deque<pii>> msgs(n + 1); // O(N * k) Memory

    char c;
    int u, v;
    int mId = 1;
    while(q--) {
        cin >> c;
        if(c == 'F') {
            // O(k)
            cin >> u;
            if(msgs[u].size()) {
                for(auto it = msgs[u].rbegin(); it != msgs[u].rend(); it++) {
                    cout << (*it).first << ' ';
                }
                cout << '\n';
                
            } else {
                cout << "EMPTY\n";
            }
        } else {
            cin >> u >> v;
            if(c == 'B') {
                // O(N)
                for(int i = 1; i <= n; i++) {
                    if(adjMat[u][i]) {
                        addMessage(mId, i, u, k, msgs);
                    }
                }

                mId++;
            } else if(c == 'S') {
                adjMat[v][u] = 1;
            } else if(c == 'U') {
                adjMat[v][u] = 0;
                remMessage(u, v, msgs);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}