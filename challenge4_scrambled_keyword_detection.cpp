#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(|S|)
Space Complexity = O(1)

*/


void solve() {
    string s, p;
    cin >> s >> p;

    vector<int> f1(26, 0), f2(26, 0);
    for(char c: p) f1[c - 'a']++;

    int i = 0;
    for(int j = 0; j < s.size(); j++) {
        f2[s[j] - 'a']++;
        while(f2[s[j] - 'a'] > f1[s[j] - 'a']) {
            f2[s[i++] - 'a']--;
        }

        if(f1 == f2) {
            cout << i << ' ';
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();

}