#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(log N * log M)
Space Complexity = O(1)

*/

double solve(vector<int>& scoresA, vector<int>& scoresB) {
    int n = scoresA.size(), m = scoresB.size();
    if(n == 0 && m == 0) return 0;
    
    int target = (n + m) / 2;
    if(m == 0) {
        if((n + m) & 1) return scoresA[target];
        else return double(scoresA[target] + scoresA[target - 1]) / 2.0;
    } else if(n == 0) {
        if((n + m) & 1) return scoresB[target];
        else return double(scoresB[target] + scoresB[target - 1]) / 2.0;
    }


    int l1 = 0, h1 = n - 1, l2 = 0, h2 = m - 1;
    int m1, m2;
    int validIdx = 0;
    while(l1 <= h1) {
        m1 = (l1 + h1) / 2;
        if(scoresB[0] >= scoresA[m1]) {
            // No element from B
            if(m1 == target) {
                if((n + m) & 1) return scoresA[m1];
                return double(scoresA[m1] + scoresA[m1 - 1]) / 2;
            } else if(m1 < target) {
                l1 = m1 + 1;
                validIdx = m1;
            } else {
                h1 = m1 - 1;
                validIdx = h1;
            }
        } else {
            auto it = lower_bound(scoresB.begin() + l2, scoresB.begin() + h2, scoresA[m1]);
            m2 = it - scoresB.begin();
            if(scoresB[m2] >= scoresA[m1]) m2--;

            if((m1 + m2 + 2) == target + 1) {
                validIdx = m1;
                break;
            } else if((m1 + m2 + 2) < target + 1) {
                l1 = m1 + 1;
                l2 = m2;

                validIdx = m1;

            } else {
                h1 = m1 - 1;
                h2 = m2;
                
                validIdx = h1;
            }
        }
    }  

    if(validIdx >= 0) {
        validIdx = min(validIdx, n - 1);
        int temp = target - validIdx - 1;

        if(temp >= 0) {
            if((n + m) & 1) return max(scoresA[validIdx], scoresB[temp]);
            int x = max(scoresA[validIdx], scoresB[temp]);
            int y = min(scoresA[validIdx], scoresB[temp]);

            if(validIdx > 0) y = max(y, scoresA[validIdx - 1]);
            if(temp > 0) y = max(y, scoresB[temp - 1]);
            return double(x + y) / 2.0;
        } else {
            // No element from B
            if((n + m) & 1) return scoresA[target];
        return double(scoresA[target] + scoresA[target - 1]) / 2.0;
        }
    } else {
        // No element from A
        if((n + m) & 1) return scoresB[target];
        return double(scoresB[target] + scoresB[target - 1]) / 2.0;
    }

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> scoresA = {1, 2}, scoresB = {3, 4};
    cout << solve(scoresA, scoresB) << '\n';


    return 0;
}