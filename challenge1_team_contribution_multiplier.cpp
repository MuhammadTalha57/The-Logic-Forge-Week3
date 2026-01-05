#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(N)
Space Complexity = O(1)

*/

vector<int> solve(vector<int>& contributions) {
    int n = contributions.size();
    if(n < 2) {return vector<int>(n, 0);}

    vector<int> impact(n, 1);
    int suf = contributions.back();
    for(int i = n - 2; i >= 0; i--) {
        impact[i] *= suf;
        suf *= contributions[i];
    }

    int pre = 1;
    for(int i = 0; i < n; i++) {
        impact[i] *= pre;
        pre *= contributions[i];
    }

    return impact;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> contributions = {1, 2, 3, 4};
    for(int x: solve(contributions)) {cout << x << ' ';}


    return 0;
}