#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;

struct comp {
    bool operator()(const pii& a, const pii& b) const {
        return a.second < b.second;
    }
};

typedef tree<pii, null_type, comp, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


/*
Asymptotic Analysis

Time Complexity = O(N Log N)
Space Complexity = O(N)

*/

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> arr(n + 1);

    ordered_set tree;

    for(int i = 1; i <= n; i++) {cin >> arr[i]; tree.insert({arr[i], i})};



    string temp;
    int x, l, r;
    while(q--) {
        cin >> temp;
        if(temp == "NEXT") {
            cin >> x;
        } else {
            cin >> l >> r;
        }
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // vector<int> deadlines = {2,1,2,1,1};
    // vector<int> profits = {100,19,27,25,15};

    // maximize_freelance_profit(deadlines, profits);

    return 0;
}