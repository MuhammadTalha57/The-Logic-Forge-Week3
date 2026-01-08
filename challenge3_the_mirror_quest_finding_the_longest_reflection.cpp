#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(N^2)
Space Complexity = O(N^2)

*/

int find_longest_mirror_length(string& s) {
    int n = s.size();
    if(n < 2) return n;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) dp[i][i] = 1;

    
    for(int i = n-1; i >= 0; i--) {
        vector<int> leftMostInd(26, -1);
        leftMostInd[s[i] - 'a'] = i;

        for(int j = i + 1; j < n; j++) {
            // Jth char is adding 

            // Drop jth char
            dp[i][j] = dp[i][j - 1];


            if(leftMostInd[s[j] - 'a'] != -1) {
                int ind = leftMostInd[s[j] - 'a'];
                // s[j] is at ind

                // Now Selecting jth char

                if(j - ind == 1) {
                    dp[i][j] = max(dp[i][j], 2);
                } else {
                    dp[i][j] = max(dp[i][j], 2 + dp[ind + 1][j - 1]);
                }                

            }

            if(leftMostInd[s[j] - 'a'] == -1) leftMostInd[s[j] - 'a'] = j;
        }
    }

    return dp[0][n-1];

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s = "a";
    cout << find_longest_mirror_length(s);

    return 0;
}