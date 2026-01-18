#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(N)
Space Complexity = O(1)

Constraints Assumption:
2*n > 1

*/

typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll x, y, temp;
    cin >> x >> y;

    if(x == y) {
        cout << x;
        return;
    }

    ll pre = y;
    ll ans = x;
    for(int i = 2; i < n; i++) {
        cin >> temp;
        if(pre == temp) {
            ans = pre;
        }
        if(temp == x) {
            ans = x;
        }
        if(temp == y) {
            ans == y;
        }


        pre = temp;
    }

    cout << ans << '\n';

    
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}