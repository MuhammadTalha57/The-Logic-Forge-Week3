#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(log.size() + pattern.size())
Space Complexity = O(1)

*/

void setAnswer(int& l, int& r, int i, int j) {
    if(l == -1 || (r - l > j - i) ) {
        l = i;
        r = j;
    }
}

int getInd(char& c) {
    if(isupper(c)) {return c - 'A';}
    else {return c - 'a' + 26;}
}

string solve(string& log, string& pattern) {
    if(pattern.size() > log.size()) return "";


    vector<int> targetFreq(52, 0), currFreq(52, 0); // Constant Space
    for(char c: pattern) {
        targetFreq[ getInd(c) ]++;
    }

    int l = -1, r = -1;
    int i = 0;
    bool found = false;

    for(int j = 0; j < log.size(); j++) {

        currFreq[getInd(log[j])]++;

        if(!found) {
            found = true;
            for(int k = 0; k < 52; k++) {
                if(currFreq[k] < targetFreq[k]) {found = false; break;}
            }

        }
        
        if(found) {

            while(currFreq[ getInd(log[i]) ] > targetFreq[ getInd(log[i]) ]) {
                // ith char can be dropped
                currFreq[ getInd(log[i++]) ]--;
            }

            setAnswer(l, r, i, j);
        }

    }

    if(r == -1) return "";
    return log.substr(l, r - l + 1);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string log = "a";
    string pattern = "a";
    cout << solve(log, pattern) << '\n';

    return 0;
}