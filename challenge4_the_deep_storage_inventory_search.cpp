#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(k Log n)
Space Complexity = O(N)

*/

int solve(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    
    set<pair<int, int>> st;
    for(int i = 0; i < n; i++) {
        st.insert({matrix[i][0], i});
        matrix[i][0] = 1;
    }

    int cnt = 0;
    while(cnt < k - 1) {
        auto [e, i] = *st.begin();
        st.erase(st.begin());

        if(matrix[i][0] < n) {
            st.insert({matrix[i][matrix[i][0]], i});
            matrix[i][0]++;
        }
        cnt++;
    }


    return (*st.begin()).first;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> matrix = {
        {1, 5, 9}, {10, 11, 13}, {12, 13, 15}
    };
    int k = 8;
    cout << solve(matrix, k) << '\n';

    return 0;
}