#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(2^n)
Space Complexity = O(N)

*/

bool comp(vector<int>& p1, vector<int>& p2) {
    if(p1[1] < p2[1]) return true;
    return false;
}

int min_cancelled_bookings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);

    int ans = 0;

    int lastEnd = INT_MIN;
    for(int i = 0; i < intervals.size(); i++) {
        if(intervals[i][0] >= lastEnd) lastEnd = intervals[i][1];
        else ans++;
    }

    return ans;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> intervals = {
        {1, 3}, {1, 3}, {1, 3}
    };

    cout << min_cancelled_bookings(intervals);


    return 0;
}