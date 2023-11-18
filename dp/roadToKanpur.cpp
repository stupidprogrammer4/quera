#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;

int dp[maxn];

int main() {
    int T, n;
    cin>>T;
    while (T--) {
        cin>>n;
        int a[n];
        for (int i = 0; i < n; i++) cin>>a[i];
        
        for (int i = 0; i < n; i++) {
            dp[i] = abs(a[i]-144);

            for (int j = 0; j < i; j++) 
                dp[i] = min(dp[i], dp[j] + abs(a[i]-a[j]-144));
        }
        cout<<dp[n-1]<<'\n';
    }
    return 0;
}