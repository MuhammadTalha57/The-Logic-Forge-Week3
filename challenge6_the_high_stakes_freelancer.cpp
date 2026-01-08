#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;

struct comp {
    bool operator()(const pii &a, const pii &b) const {
        return a.second < b.second;
    }
};

typedef tree<pii, null_type, comp, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


/*
Asymptotic Analysis

Time Complexity = O(N Log N)
Space Complexity = O(N)

*/

pair<int, int> maximize_freelance_profit(vector<int>& deadlines, vector<int>& profits) {

    vector<pair<int, int>> arr;
    for(int i = 0; i < deadlines.size(); i++) {
        arr.push_back({deadlines[i], profits[i]});
    }

    sort(arr.begin(), arr.end());

    int maxProfit = 0;
    int jobs = 0;

    set<pair<int, int>> st;


    int j = deadlines.size() - 1;
    int t = arr[j].first;

    while(t) {
        if(j >= 0) {    
            if(arr[j].first == t) {
                for(int i = j; i >= 0; i--) {
                    if(arr[i].first == arr[j].first) {
                        st.insert({-arr[i].second, i});
                        j = i;
                    } else {break;}
                }
        
                j--;
            }
        }
        
        if(st.size()) {
            
            maxProfit -= (*st.begin()).first;
            jobs++;
    
            st.erase(st.begin());
        }

        t--;

    }
    // cout << jobs << ' ' << maxProfit << '\n';
    return {jobs, maxProfit};

}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> deadlines = {2,1,2,1,1};
    vector<int> profits = {100,19,27,25,15};

    maximize_freelance_profit(deadlines, profits);

    return 0;
}