#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 30; // log(10^13) / log(3) < 30 
vector<ll> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59}; //prime numbers < 30*2=max amount of 30 digit number base 3
ll dp[N][N*2], n, k, ans;

ll solve(ll k, ll digit, ll before) {
    if (digit == -1)
        return 0;
    ll sum = 0, lastSum = 0;
    for (ll d = 0; d < 3; d++) {
        for (auto p : primes) 
            if (p >= d+before)
                sum += dp[digit][p-d-before];

        if (sum >= k) 
            return 1LL*d*std::pow(3, digit) + solve(k-lastSum, digit-1, before+d);

        lastSum = sum;
    }

    return -1LL;
}

int main() {
    memset(dp, 0, sizeof(dp));
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 0; i < N; i++) dp[i][1] = i;
    for (int i = 0; i < N; i++) dp[i][0] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 2; j < N*2; j++)
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2];

    int T;
    cin>>T;
    while (T--) {
        cin>>n>>k;
        ans = solve(k, N-1, 0);
        if (ans > n)
            ans = -1;
        cout<<ans<<'\n';
    }
}