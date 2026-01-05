#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(NM)
Space Complexity = O(NM)

Efficient for N, M <= O(10^3)

*/

bool solve(string& text, string& pattern) {
    int n = text.size(), m = pattern.size();
    if(n == 0 && m == 0) return true;
    if(m == 0) return false;
    if(n == 0) return count(pattern.begin(), pattern.end(), '*') == m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Define for i = 0
    for(int j = 1; j <= m; j++) {
        if(pattern[j - 1] == '*') dp[0][j] = 1;
        else {break;}
    }

    // Define for j = 1
    for(int i = 1; i <= n; i++) {
        if(pattern[0] == '*') dp[i][1] = 1;
    }

    // Define for [1][1]
    dp[1][1] = pattern[0] == '*' || pattern[0] == '?' || pattern[0] == text[0];

    vector<int> columnCheck(m + 1, 0);
    for(int j = 0; j <= m; j++) {
        columnCheck[j] = dp[0][j];
    }

    // Populate
    for(int i = 1; i <= n; i++) {
        columnCheck[1] = columnCheck[1] || dp[i][1];
        for(int j = 2; j <= m; j++) {
            if(pattern[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];

            } else if(pattern[j - 1] == '*') {
                dp[i][j] = columnCheck[j - 1];

            } else {
                dp[i][j] = text[i - 1] == pattern[j - 1] && dp[i - 1][j - 1];
            }
            columnCheck[j] = columnCheck[j] || dp[i][j];
        }
    }

    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string text = "ab", pattern = "*a";
    cout << solve(text, pattern);


    return 0;
}