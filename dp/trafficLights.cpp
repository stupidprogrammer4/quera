#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int dp[maxn][5];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    string s;
    cin>>t;

    vector<char> chars = {'G', 'Y', 'R'};

    while (t--) {
        cin>>n;
        cin>>s;

        for (int i=1; i<=n; i++) {
            for (int j=0; j<3; j++) {
                if (s[i-1] == chars[j])
                    dp[i][j] = max(dp[i-1][((j-1)+3)%3]+1, dp[i-1][j]+1);
                else
                    dp[i][j] = dp[i-1][j];

            }
        }

        int ans = 0;

        for (int i=0; i<3; i++)
            ans = max(ans, dp[n][i]);

        cout<<ans<<'\n';

    }
}