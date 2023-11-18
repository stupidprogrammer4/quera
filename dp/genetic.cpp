#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+10;
int dp[maxn];

int main() {
    int n, m;
    string s, t;
    cin>>s>>t;
    n = s.length(), m = t.length();
    map<char, int> cost = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    for (auto c : cost)
    {
        int t;
        cin>>t;
        cost[c.first] = t;
    }
    int ans = INT32_MAX;
    for (int i=0; i<n; i++) {
        int k = 0, sum = 0;
        for (int j=0; j<m; j++) {
            if (s[i+k] == t[j] && i + k < n) {
                k++;
                continue;
            }
            sum += cost[t[j]];
        }
        ans = min(sum, ans);
    }

    cout<<ans<<'\n';
}