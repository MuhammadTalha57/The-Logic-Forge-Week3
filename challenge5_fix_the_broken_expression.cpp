#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(2^n)
Space Complexity = O(N)

*/

bool isValid(string& expr, int mask, int total, int minRemovals, set<string>& res) {
    if(total - __popcount(mask) != minRemovals) return false;

    int k = 0;
    int open = 0;
    for(char c: expr) {
        if(c == '(' || c == ')') {
            if((1 << k) & mask) {
                if(c == '(') open++;
                else open--;
            }
            if(open < 0) return false;

            k++;
        }
    }

    return open == 0;
}

vector<string> solve(string& expr) {
    int total = count(expr.begin(), expr.end(), '(') + count(expr.begin(), expr.end(), ')');

    int minRemovals = 0;
    int open = 0;
    for(char c: expr) {
        if(c == '(') open++;
        else if(c == ')') open--;
        
        if(open < 0) minRemovals++;
        open = max(open, 0);
    }
    minRemovals += open;

    set<string> res;
    for(int mask = 0; mask < (1 << total); mask++) {
        if(isValid(expr, mask, total, minRemovals, res)) {
            string temp = "";
            int k = 0;
            for(char c: expr) {
                if(c == '(' || c == ')') {
                    if((1 << k) & mask) {
                        temp += c;
                    }
                    k++;
                }
                else temp += c;
            }
            res.insert(temp); // Constant Time cuz length of string is <= 25
        }
    }

    return vector<string>(res.begin(), res.end());

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string expr = "(a)())()";
    for(string s: solve(expr)) {cout << s << ' ';}


    return 0;
}